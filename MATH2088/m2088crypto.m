////////////////////////////////////////////////////////////////////////
//                                                                    //  
//                       PUBLIC KEY CRYPTOSYSTEMS                     //
//                             David Kohel                            //
//                              May 2000                              //
//                                                                    // 
////////////////////////////////////////////////////////////////////////

ALPHABET := ["A","B","C","D","E","F","G","H","I","J","K","L","M",
             "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]; 

intrinsic RSACryptosystem(m::RngIntElt) -> Crypt
    {The RSA cryptosystem of block length m bits, and moduli
    bounded by m bits.}
    require m gt 0 : "Argument must be a positive integer.";
    require m mod 64 eq 0 : "Argument must be divisible by 64.";
    C := New(Crypt);
    C`IsSymmetric := false;
    C`CipherType := "RSA";
    C`BlockLength := m;
    return C;
end intrinsic;

function XCRT(A,M)
    a1 := A[1]; a2 := A[2]; m1 := M[1]; m2 := M[2];
    m0 := GCD(m1,m2); m1 div:= m0; m2 div:= m0;
    c0 := a1 mod m0;
    c1 := CRT([(a1-c0) div m0,(a2-c0) div m0],[m1,m2]);
    return c0 + c1*m0 mod (m0*m1*m2);
end function;

intrinsic RandomKeys(C::Crypt : Exponent := 0) -> CryptKey, CryptKey
    {Given an RSA cryptosystem, generates an RSA public-private key
    pair, with modulus bounded in bits by the block length of C.}
    require CipherType(C) eq "RSA" :
       "Argument 1 must be an RSA cryptosystem.";
    m := BlockLength(C);
    p := RandomPrime(m div 2 : Proof := false);
    while Exponent ne 0 and GCD(p-1,Exponent) ne 1 do
        p := RandomPrime(m div 2 : Proof := false);
    end while;
    q := RandomPrime(m div 2 : Proof := false);
    // Might have p = q for trivially small m:
    while (Exponent ne 0 and GCD(q-1,Exponent) ne 1) or q eq p do
       q := RandomPrime(m div 2 : Proof := false);
    end while;
    n := p*q;
    if Exponent eq 0 then
        e := Random(n);
        while GCD(e,p-1) ne 1 or GCD(e,q-1) ne 1 do
            e := Random(n);
        end while;
    else
        e := Exponent;
    end if;
    // Compute the public enciphering key:
    K := New(CryptKey);
    K`Parent := C;
    K`IsEnciphering := true;
    K`KeyString := [e,n];
    // Compute the private deciphering key:
    f := XCRT([InverseMod(e,p-1),InverseMod(e,q-1)],[p-1,q-1]);
    L := New(CryptKey);
    L`Parent := C;
    L`IsEnciphering := false;
    L`KeyString := [f,n];
    return K, L;
end intrinsic;

intrinsic IsPublicPrivatePair(K::CryptKey,L::CryptKey) -> BoolElt
    {Given two RSA keys K and L, returns true if and only
    if the K and L are inverse keys.}
    C := Parent(K);
    require C eq Parent(L) : 
       "Arguments must have the same parent cryptosystem.";
    require CipherType(C) eq "RSA" : "Arguments must be RSA keys.";
    e, n := Explode(K`KeyString);
    f, m := Explode(L`KeyString);
    if n ne m then return false; end if;
    return Modexp(2,e*f-1,n) eq 1 and Modexp(3,e*f-1,n) eq 1;
end intrinsic;

intrinsic RSAExponent(K::CryptKey) -> RngIntElt
    {}
    return String(K)[1];
end intrinsic;

intrinsic RSAModulus(K::CryptKey) -> RngIntElt
    {}
    return String(K)[2];
end intrinsic;

function BitsToInteger(S)
    S := ChangeUniverse(S,Integers());
    return &+[ S[i]*2^(i-1) : i in [1..#S] ];
end function;

function IntegerToBits(n,t)
    S := [ GF(2) | ];
    for i in [1..t] do
        Append(~S,n mod 2);
        n div:= 2;
    end for;
    return S;
end function;

function RSAEnciphering(K,MS)
    // INPUT: MS is the bit sequence of the message string.
    // OUTPUT: Ciphertext bit sequence CS. 
    C := Parent(K);
    m := BlockLength(C);
    e, n := Explode(String(K));
    CS := [ Integers() | ];
    error if not #MS mod m eq 0,
        "Block length must divide the length of an encoded bit sequence.";
    // This should be moved to the encoding algorithm.
    // MS cat:= [ GF(2)!0 : i in [1..((t-#MS) mod t)] ];
    max := #MS div m;
    for i in [1..max] do
        mi := BitsToInteger(MS[m*(i-1)+1..m*i]);
        error if mi gt n, "Integer represented by bit sequence " *
            "must be bounded by the RSA modulus.";
        /*
        // This should be moved to the encoding algorithm.
        if i eq max then
            h := 8*Ceiling(Log(256,mi));
            k := Floor(Log(2,n));
            if h+8 lt m then
                mi +:= &*[ Random({0,1})*2^i : i in [h+8..k] ];
            end if;
        end if;
        */
        ci := Modexp(mi,e,n);
        Append(~CS,ci);
    end for;
    return &cat[ IntegerToBits(ci,m) : ci in CS ];
end function;

////////////////////////////////////////////////////////////////////////
//                                                                    //  
//                            CRYPTOSYSTEMS                           //
//                             David Kohel                            //
//                            February 2000                           //
//                                                                    // 
////////////////////////////////////////////////////////////////////////

Alphabet := ["A","B","C","D","E","F","G","H","I","J","K","L","M",
             "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]; 

declare verbose Crypt, 2;

////////////////////////////////////////////////////////////////////////
//                       ATTRIBUTION DECLARATIONS                     //
////////////////////////////////////////////////////////////////////////

declare type Crypt;
declare type CryptKey;

declare attributes Crypt : 
   CipherType,
   IsSymmetric,
   BlockLength,
   Domain,
   Codomain;

////////////////////////////////////////////////////////////////////////
//                                                                    // 
//                     ENCODING SPECIFICATION                         // 
//                                                                    // 
////////////////////////////////////////////////////////////////////////

function EncodingType(C)
    if CipherType(C) in {"LFSR","ShrinkingGenerator"} then
        return "Binary";
    elif CipherType(C) eq "RSA" then
        return "RSA";
    else
        return "Alphabetic";
    end if;
end function;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                          CONSTRUCTORS                              //
//                                                                    // 
////////////////////////////////////////////////////////////////////////

intrinsic SubstitutionCryptosystem() -> Crypt
    {}
    C := New(Crypt);
    C`IsSymmetric := true;
    C`CipherType := "Substitution";
    return C;
end intrinsic;

intrinsic SubstitutionCryptosystem(Alph::SetIndx) -> Crypt
    {}
    C := New(Crypt);
    C`IsSymmetric := true;
    C`CipherType := "Substitution";
    C`Domain := Alph;
    C`Codomain := Alph;
    return C;
end intrinsic;

intrinsic TranspositionCryptosystem(m::RngIntElt) -> Crypt
    {}
    C := New(Crypt);
    C`IsSymmetric := true;
    C`CipherType := "Transposition";
    C`BlockLength := m;
    return C;
end intrinsic;

intrinsic VigenereCryptosystem(m::RngIntElt) -> Crypt
    {The Vigenere cryptosystem of block length m.}
    C := New(Crypt);
    C`IsSymmetric := true;
    C`CipherType := "Vigenère";
    C`BlockLength := m;
    return C;
end intrinsic;

intrinsic LFSRCryptosystem() -> Crypt
    {The linear feedback shift register cryptosystem.}
    C := New(Crypt);
    C`IsSymmetric := true;
    C`CipherType := "LFSR";
    return C;
end intrinsic;

intrinsic ShrinkingGeneratorCryptosystem() -> Crypt
    {The shrinking generator cryptosystem, based on a pair of
    linear feedback shift registers.}
    C := New(Crypt);
    C`IsSymmetric := true;
    C`CipherType := "ShrinkingGenerator";
    return C;
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                  COERCION AND KEY CREATION                         // 
//                                                                    // 
////////////////////////////////////////////////////////////////////////

intrinsic IsCoercible(C::Crypt,W::.) -> BoolElt, MonStgElt
   {}
   if Type(W) eq CryptKey then
       if C eq Parent(W) then
           return true, W;
       end if;
   elif Type(W) eq MonStgElt then
       if C`CipherType notin {"Vigenère","Substitution"} then
           return false, "Invalid coercion.";
       end if;
       // Test that the key length is valid.
       if not assigned C`Domain then
           W := StripEncoding(W : WildCharacter := "*");
           m := assigned C`BlockLength select C`BlockLength else #W;
       else
           m := #C`Domain;
       end if;
       if m eq #W or m eq 0 then
           K := New(CryptKey);
           K`Parent := C;
           K`IsEnciphering := true;
           K`KeyString := W;
           return true, K;
       end if;
   elif Type(W) eq SeqEnum then
       if C`CipherType eq "ShrinkingGenerator" then
           S := Universe(W);
           if Type(S) ne Crypt or #W ne 2 or 
               S`CipherType ne "LFSR" then
               return false, "Invalid coercion.";
           end if;
           K := New(CryptKey);
           K`Parent := C;
           K`IsEnciphering := true;
           K`KeyString := W;
           return true, K;
       elif C`CipherType eq "RSA" then
           if Type(Universe(W)) ne RngInt or #W ne 2 then
               return false, "Invalid coercion.";
           end if;
           K := New(CryptKey);
           K`Parent := C;
           K`IsEnciphering := true;
           K`KeyString := W;
           return true, K;
       elif C`CipherType notin {"Transposition"} then
           return false, "Invalid coercion.";
       end if;
       m := assigned C`BlockLength select C`BlockLength else #W;
       if Type(Universe(W)) ne RngInt then
           return false, "Invalid coercion.";
       elif SequenceToSet(W) ne {1..m} then
           if 0 notin W then
               return false, "Invalid coercion.";
           else
               W1 := [ i : i in W | i ne 0 ];
               if #W1 ne #SequenceToSet(W1) or
                   &or [ i notin {1..m} : i in W1 ] then
                   return false, "Invalid coercion.";
               end if; 
           end if;
       end if;
       K := New(CryptKey);
       K`Parent := C;
       K`IsEnciphering := true;
       K`KeyString := W;
       return true, K;
   elif Type(W) eq SetIndx then
       if not assigned C`Domain or C`CipherType ne "Substitution" then
           return false, "Invalid coercion";
       end if;
       m := #C`Domain;
       if m eq #W or m eq 0 then
           K := New(CryptKey);
           K`Parent := C;
           K`IsEnciphering := true;
           K`KeyString := W;
           return true, K;
       end if;
   elif Type(W) eq Tup then
       if C`CipherType notin {"LFSR"} then
           return false, "Invalid coercion.";
       end if;
       if Type(W[1]) ne RngUPolElt or Type(W[2]) ne SeqEnum
           or Degree(W[1]) ne #W[2] then
           return false, "Invalid coercion.";
       end if;
       K := New(CryptKey);
       K`Parent := C;
       K`IsEnciphering := true;
       K`KeyString := "";
       K`ConnectionPolynomial := W[1];
       K`InitialState := W[2];
       return true, K;
   end if;
   return false, "Invalid coercion.";
end intrinsic;

intrinsic RandomKey(C::Crypt) -> CryptKey
    {}
   if C`CipherType eq "Substitution" then
       if not assigned C`Domain then
           K := RandomSubstitutionKey();
       else
           S := C`Domain;
           K := {@ @};
           for i in [1..#S] do
               c := Random(S);
               Include(~K,c);
               Exclude(~S,c);
           end for;
       end if;
       return C!K;
   elif C`CipherType eq "Transposition" then
       require assigned C`BlockLength : "Attribute BlockLength must be " *
           "assigned to construct a random key.";
       m := C`BlockLength;
       I := [1..m];
       K := [];
       for i in [1..m] do
           j := Random(I);
           Exclude(~I,j);
           Append(~K,j);
       end for;
       return C!K;
   elif C`CipherType eq "Vigenère" then
       require assigned C`BlockLength : "Attribute BlockLength must be " *
           "assigned to construct a random key.";
       return C!&cat[ Random(Alphabet) : i in [1..C`BlockLength] ];
   end if;
   require false : "No random key constructor for this cryptosystem.";
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                            PRINTING                                //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic Print(C::Crypt, level::MonStgElt)
    {}
    printf C`CipherType cat " cryptosystem";
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                            EQUALITY                                //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic 'eq'(C::Crypt,S::Crypt) -> BoolElt
    {}
    return IsIdentical(C, S);
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//               ENCODING, ENCIPHERING AND DECIPHERING                //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic Decoding(S::CryptTxt) -> MonStgElt
    {Given cryptographic text, return the associated decoded string.
    Note that certain alphabetic encodings used here are non-invertible,
    and the decoding does not give back the original message text.
    Also note that the decoding of ciphertext is still an enciphered
    string.  The encoding of the decoded cryptographic text will return 
    the original cryptographic text.}

    type := EncodingType(Cryptosystem(S));
    if type eq "Alphabetic" then
        return S`String;
    elif type eq "Binary" then
        return BitDecoding(S`String);
    elif type eq "RSA" then
        C := Cryptosystem(S);
        m := BlockLength(C);
        t := m-8;
        MS := S`String;
        // #MS div t???
        is_plaintext :=
           &and [ &and [ 0 eq MS[i*m-8+j] : j in [1..8] ]
              : i in [1..#MS div t] ];
        require is_plaintext : "Argument is not valid plaintext.";
        DecStr := &cat[ MS[(i-1)*m+1..i*m-8] : i in [1..#MS div t] ];
        return BitDecoding(DecStr);
    end if;
    require false : "Unknown encoding type for cryptosystem.";
end intrinsic;

intrinsic Encoding(C::Crypt,M::MonStgElt) -> CryptTxt
    {Given a message text W, encode the message in the domain of 
    plaintext for the cryptosystem.}

    S := New(CryptTxt);
    S`Cryptosystem := C;
    S`IsPlainText := true;
    type := EncodingType(Cryptosystem(S));
    if type eq "Alphabetic" then
        if not assigned C`Domain then
            S`String := StripEncoding(M : WildCharacter := "*");
        else
            S`String := M;
        end if;
    elif type eq "RSA" then
        MS := BitEncoding(M);
        m := BlockLength(C);
        t := (m-8);
        MS cat:= [ GF(2) | 0 : i in [1..t - (#MS mod t)] ];
        Z := [ GF(2) | 0 : i in [1..8] ];
        MS := &cat[ MS[(i-1)*t+1..i*t] cat Z : i in [1..(#MS div t)] ];
        S`String := MS;
    else
        S`String := BitEncoding(M);
    end if;
    return S;
end intrinsic;

intrinsic Encoding(C::Crypt,W::[FldFinElt]) -> CryptTxt
    {Given a binary message text W, encode the message for
    the cryptosystem C.}

    require EncodingType(C) eq "Binary" :
        "Argument 1 must use binary encoding.";
    require Universe(W) eq GF(2) :
        "Argument 2 must be a binary sequence.";
    S := New(CryptTxt);
    S`Cryptosystem := C;
    S`String := W;
    return S;
end intrinsic;

/*
function SubstitutionEnciphering(K,PT)
    n := #PT;
    I := [ StringToCode(PT[i])-64 : i in [1..n] ];
    I := [ I[i] eq -22 select 27 else I[i] : i in [1..#I] ]; 
    K cat:= "*";
    return &cat[ I[i] eq -54 select "\n" else K[I[i]] : i in [1..n] ];
end function;
*/

function TranspositionEnciphering(K,PT)
    m := #K;
    N := #PT;
    k := N mod m;
    if k ne 0 then
        PT cat:= &cat[ Random(Alphabet) : i in [m-k] ]; 
    end if;
    CT := "";
    k := 0;
    while k+m le N do
        CT cat:= &cat[ K[i] eq 0 select "*"
           else PT[k+K[i]] : i in [1..m] ];
        k +:= m;
    end while;
    return CT;
end function;

/*
function HomophonicEnciphering(S,PT)
    m := #S;
    n := #PT;
    indx := [ StringToCode(PT[i])-64 : i in [1..n] ];
    return &cat[ indx[i] eq -54 select "\n"
                 else S[Random([1..m])][indx[i]] : i in [1..n] ];
end function;
*/

function VigenereEnciphering(K,PT)
    m := #K;
    n := #PT;
    indx := [ StringToCode(PT[i])-65 : i in [1..n] ];
    j := 1;
    X := "";
    for i in [1..n] do
        if indx[i] eq -55 then
            /* Newline character is code 10. */ 
            X cat:= "\n";
        else
            k := StringToCode(K[((j-1) mod m)+1])-65;
            if k eq -23 or indx[i] eq -23 then
                /* Character "*" is code 42. */ 
                X cat:= "*";
            else
                X cat:= CodeToString(((indx[i] + k) mod 26)+65);
            end if;
            j +:= 1;
        end if;
    end for;
    return X;
end function;

function LFSREnciphering(K,PT)
    g := K`ConnectionPolynomial;
    IS := K`InitialState;
    n := #PT;
    KS := LFSRSequence(g,IS,n);
    return [ PT[i] + KS[i] : i in [1..n] ]; 
end function;

intrinsic Deciphering(K::CryptKey,CT::CryptTxt) -> MonStgElt
    {}
    C := Parent(K);
    require C eq Cryptosystem(CT) :
        "Arguments have incompatible cryptosystems.";
    if C`IsSymmetric then
        return Enciphering(InverseKey(K),CT);
    elif CipherType(C) eq "RSA" then
        CS := String(CT);
        MS := RSAEnciphering(K,CS);
        X := New(CryptTxt);
        X`Cryptosystem := C;
        X`IsPlainText := true;
        X`String := MS;
        return X;
    end if;
    require false : 
        "Parent of argument 1 must be a symmetric key cryptosystem.";
end intrinsic;

intrinsic Enciphering(K::CryptKey,M::CryptTxt) -> MonStgElt
    {}
    C := K`Parent;
    require C eq M`Cryptosystem :
        "Arguments have incompatible cryptosystems.";
    KS := K`KeyString;
    PT := M`String;
    if C`CipherType eq "Substitution" then
        if not assigned C`Domain then
            CT := SubstitutionEnciphering(KS,PT : Encode := false);
        else
            CT := SubstitutionEnciphering(C`Domain,KS,PT);
        end if;
        X := New(CryptTxt);
        X`Cryptosystem := C;
        X`IsPlainText := false;
        X`String := CT;
        return X;
    elif C`CipherType eq "Transposition" then
        CT := TranspositionEnciphering(KS,PT);
        X := New(CryptTxt);
        X`Cryptosystem := C;
        X`IsPlainText := false;
        X`String := CT;
        return X;
    elif C`CipherType eq "Vigenère" then
        CT := VigenereEnciphering(KS,PT);
        X := New(CryptTxt);
        X`Cryptosystem := C;
        X`IsPlainText := false;
        X`String := CT;
        return X;
    elif C`CipherType eq "LFSR" then
        CT := LFSREnciphering(K,PT);
        X := New(CryptTxt);
        X`Cryptosystem := C;
        X`IsPlainText := false;
        X`String := CT;
        return X;
    elif C`CipherType eq "RSA" then
        CT := RSAEnciphering(K,PT);
        X := New(CryptTxt);
        X`Cryptosystem := C;
        X`IsPlainText := false;
        X`String := CT;
        return X;
    end if;
    error "Enciphering algorithm unknown for this cryptosystem."; 
end intrinsic;

/////////////////////////////////////////////////////////////////////////
//                                                                     //
//                         ATTRIBUTE ACCESS                            //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

intrinsic CipherType(C::Crypt) -> MonStgElt
    {The string identifying the cryptographic algorithm of C.}
    return C`CipherType;
end intrinsic;

intrinsic BlockLength(C::Crypt) -> MonStgElt
    {The string identifying the cryptographic algorithm of C.}
    require assigned C`BlockLength :
       "Attribute BlockLength is not assigned for argument.";
    return C`BlockLength;
end intrinsic;

intrinsic DomainAlphabet(C::Crypt) -> SeqEnum
    {}
    type := EncodingType(C);
    if type eq "Binary" then
        return GF(2);
    elif type eq "Alphabetic" then
        return Alphabet;
    end if;
    require false : "Argument cryptosystem has unknown alphabet type.";
end intrinsic;

intrinsic CodomainAlphabet(C::Crypt) -> SeqEnum
    {}
    type := EncodingType(C);
    if type eq "Binary" then
        return GF(2);
    elif type eq "Alphabetic" then
        return Alphabet;
    end if;
    require false : "Argument cryptosystem has unknown alphabet type.";
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //  
//                     ASSOCIATED KEYS OF CRYPTOSYSTEMS               //
//                             David Kohel                            //
//                            February 2000                           //
//                                                                    // 
////////////////////////////////////////////////////////////////////////

/*
We view a cryptosystem as a collection of ciphers (= an enciphering
and deciphering map pair), each of which is parametrized by a key or
key pair.  By equating the ciphers with the keys which parameterize
them, the cryptosystem keys are therefore *defined* as elements of
the cryptosystem.  
*/


////////////////////////////////////////////////////////////////////////
//                       ATTRIBUTION DECLARATIONS                     //
////////////////////////////////////////////////////////////////////////

declare attributes CryptKey : 
    Parent,
    IsEnciphering,  // true or false (= Deciphering)
    KeyString,
    // For LFSR stream ciphers:
    ConnectionPolynomial,
    InitialState;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                            PRINTING                                //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic Print(K::CryptKey, level::MonStgElt)
    {}
    if Parent(K)`CipherType eq "LFSR" then
        printf "<%o, %o>", K`ConnectionPolynomial,
            &cat[ IntegerToString(ZZ!c) : c in K`InitialState ]
                where ZZ := Integers();
    else 
        printf "%o", K`KeyString;
    end if;
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                            EQUALITY                                //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic 'eq'(C::CryptKey,S::CryptKey) -> BoolElt
    {}
    return C`Parent eq S`Parent and C`KeyString eq S`KeyString;
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                            PARENTS                                 //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic Parent(K::CryptKey) -> Crypt
    {}
    return K`Parent;
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                         ATTRIBUTE ACCESS                           //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic String(K::CryptKey) -> MonStgElt
    {The string -- (usually, but not always) of type MonStgElt --
    of the cryptogrphic key, otherwise the defining data.}
    return K`KeyString;
end intrinsic;

intrinsic InverseKey(K::CryptKey) -> CryptKey
    {The inverse key of a symmetric cryptosystem.}
    C := Parent(K);
    require C`IsSymmetric :
        "Parent of argument must be a symmetric key cryptosystem.";
    if C`CipherType eq "Substitution" then
        S := String(K);
        AZ := DomainAlphabet(C);
        return C!&cat[ i eq 0 select "*" else AZ[i] where
           i := Index(S,AZ[i]) : i in [1..#S] ];
    elif C`CipherType eq "Transposition" then
        P := K`KeyString; // = permutation sequence of integers
        m := #P;
        R := [ 0 : i in [1..m] ];
        for i in [1..m] do
            R[P[i]] := i;
        end for;
        return C!R;
    elif C`CipherType eq "Vigenère" then
        S := String(K);
        AZ := DomainAlphabet(C);
        return C!&cat[
            n eq 0 select "*" else AZ[ n eq 1 select 1 else 28-n ]
            where n := Index(AZ,S[i]) : i in [1..#S] ];
    elif C`CipherType eq "LFSR" then
        return K;
    end if;
    require false : "Unknown cryptosystem type.";
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //  
//                 PLAIN AND CIPHER TEXT OF CRYPTOSYSTEMS             //
//                             David Kohel                            //
//                            February 2000                           //
//                                                                    // 
////////////////////////////////////////////////////////////////////////

/*
In lieu of differentiated string monoids, this gives a validity check
that a string belongs to the domain (of plaintext) or the codomain
(of ciphertext) of a cryptosystem.
*/

////////////////////////////////////////////////////////////////////////
//                       ATTRIBUTION DECLARATIONS                     //
////////////////////////////////////////////////////////////////////////

declare type CryptTxt;

declare attributes CryptTxt : 
    Cryptosystem,
    IsPlainText,  // true or false (= Deciphering)
    String;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                            PRINTING                                //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic Print(T::CryptTxt, level::MonStgElt)
    {}
    C := T`Cryptosystem;
    if EncodingType(C) in {"Binary","RSA"} then
        ZZ := Integers();
        printf "%o", &cat[ IntegerToString(ZZ!c) : c in T`String ];
    else        
        printf "%o", T`String;
    end if;
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                            EQUALITY                                //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic 'eq'(C::CryptTxt,S::CryptTxt) -> BoolElt
    {}
    return C`Cryptosystem eq S`Cryptosystem and C`String eq S`String;
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                         ATTRIBUTE ACCESS                           //
//                                                                    //
////////////////////////////////////////////////////////////////////////

intrinsic Cryptosystem(W::CryptTxt) -> Crypt
    {The cryptosytem of W.}
    return W`Cryptosystem;
end intrinsic;

intrinsic String(K::CryptTxt) -> MonStgElt
    {The key string -- of type MonStgElt -- the cryptogrphic key.}
    return K`String;
end intrinsic;

intrinsic IsPlainText(W::CryptTxt) -> Crypt
    {Returns true if and only if W is plaintext.}
    return W`IsPlainText;
end intrinsic;

intrinsic IsCipherText(W::CryptTxt) -> Crypt
    {Returns true if and only if W is ciphertext.}
    return not W`IsPlainText;
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    // 
//                           CRYPTANALYSIS                            // 
//                            David Kohel                             //
//                           February 2001                            //
//                                                                    // 
//////////////////////////////////////////////////////////////////////// 

Alphabet := ["A","B","C","D","E","F","G","H","I","J","K","L","M",
             "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]; 
alphabet := ["a","b","c","d","e","f","g","h","i","j","k","l","m",
             "n","o","p","q","r","s","t","u","v","w","x","y","z"]; 

////////////////////////////////////////////////////////////////////////
//                                                                    // 
//                         FREQUENCY MATCHING                         //
//                                                                    // 
////////////////////////////////////////////////////////////////////////

intrinsic TranslationCorrelations(S1::[FldReElt],S2::[FldReElt])
    -> SeqEnum
    {The sequence of correlations of the sequence S1 with the 
    cyclic translations of the sequence S2.}

    n := #S1;
    require n eq #S2 : "Arguments must be of the same length."; 

    // Compute the mean value of each sequence: 
    mu1 := &+[ S1[k] : k in [1..n] ]/n;
    mu2 := &+[ S2[k] : k in [1..n] ]/n;

    // Compute the standard deviations of each sequence:
    sig1 := Sqrt(&+[ (S1[k]-mu1)^2 : k in [1..n] ]);
    sig2 := Sqrt(&+[ (S2[k]-mu2)^2 : k in [1..n] ]);

    sig := sig1*sig2;
    CorrSeq := [ ];
    for j in [1..n] do
        Corr := &+[ (S1[i] - mu1) * (S2[ij] - mu2) / sig
            where ij := ((i+j-1) mod n) + 1 : i in [1..n] ];
        Append(~CorrSeq,<j,Corr>);
    end for;
    return CorrSeq;
end intrinsic;

intrinsic TranslationMatches(S::MonStgElt,F::[FldReElt],r::FldReElt) 
    -> SeqEnum 
    {}
    n := 26;
    require #F eq n : "Argument 2 must have 26 elements.";
    X := FrequencyDistribution(S);
    CorrSeq := TranslationCorrelations(X,F);
    return [ x[1] : x in CorrSeq | x[2] gt r ];
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    // 
//                         FREQUENCY ANALYSIS                         //
//                                                                    // 
////////////////////////////////////////////////////////////////////////

intrinsic Frequency(CT::CryptTxt,W::MonStgElt) -> Fld
    {The number of occurrences of a string W in the ciphertext CT 
    length r, divided by the total number #CT-#W+1 of substrings
    of length #W in CT.}
    return Frequency(String(CT),W);
end intrinsic; 

intrinsic Frequency(CT::MonStgElt,W::MonStgElt) -> Fld
    {The number of occurrences of a string W in the ciphertext CT 
    length r, divided by the total number #CT-#W+1 of substrings
    of length #W in CT.}
    k := #W;
    N := #CT;
    RR := RealField();
    return &+[ RR | 1.0 : i in [1..N-k+1] | CT[[i..i+k]] eq W ]/(N-k+1);
               
end intrinsic; 

intrinsic FrequencyDistribution(W::CryptTxt :
    Precision := 8) -> SeqEnum
    {}
    return FrequencyDistribution(String(W) : Precision := Precision);
end intrinsic;

intrinsic FrequencyDistribution(W::MonStgElt : 
    Precision := 8) -> SeqEnum
    {}
    W := StripEncoding(W : WildCharacter := "*");
    n := #W;
    S := [ 0 : i in [1..26] ];
    for i in [1..n] do
        k := Index(Alphabet,W[i]);
        if k ne 0 then S[k] +:= 1; end if;
    end for;
    return [ RealField() | RealField(Precision)!e/n : e in S ];
end intrinsic;

intrinsic FrequencyDistribution(W::CryptTxt : Precision := 8) -> SeqEnum
    {}
    return FrequencyDistribution(String(W) : Precision := Precision);
end intrinsic;

intrinsic DigraphFrequencyDistribution(W::CryptTxt : Precision := 8)
    -> SeqEnum {}
    return DigraphFrequencyDistribution(
        String(W) : Precision := Precision);
end intrinsic;

intrinsic DigraphFrequencyDistribution(W::MonStgElt :
    Precision := 8) -> AlgMatElt
    {The number of occurrences of a character C in the string W.}
    require #W ge 2 :
        "Argument 1 must be of length at least 2.";
    RR := RealField();
    M := MatrixAlgebra(RR,26)!0;
    u := RR!RealField(Precision)!(1/(#W-1));
    i := Index(Alphabet,W[1]);
    for k in [2..#W] do
        j := Index(Alphabet,W[k]);
        if j ne 0 then
            M[i,j] +:= u;
            i := j;
        end if;
    end for;
    return M;
end intrinsic; 

intrinsic PolygraphFrequencyDistribution(S::MonStgElt,n::RngIntElt,r::FldReElt)
    -> SetIndx, SeqEnum
    {The indexed set of substrings of length n occurring with frequency
    at least r, followed by the sequence of frequencies.}
    N := #S-n-1;
    s := Ceiling(r*N);
    MS := SequenceToMultiset([ S[[i..i+n-1]] : i in [1..N] ]);
    IS := {@ Strings() | @};
    SQ := [ RealField() | ];
    for W in Set(MS) do
        m := Multiplicity(MS,W);
        if m ge s then
            Include(~IS,W);
            Append(~SQ,1.0*m/N);
        end if;
    end for;
    return IS, SQ;
end intrinsic;

intrinsic CoincidenceIndex(W::CryptTxt) -> FldReElt
    {}
    return CoincidenceIndex(String(W));
end intrinsic;

intrinsic CoincidenceIndex(W::MonStgElt) -> FldReElt
    {}
    RR := RealField();
    W := StripEncoding(W : WildCharacter := "*");
    n := #W;
    S := [ 0 : i in [1..26] ];
    for i in [1..n] do
        k := Index(Alphabet,W[i]);
        if k ne 0 then S[k] +:= 1; end if;
    end for;
    return &+[ RR | 1.0*c*(c-1) : c in S ]/(RR!1.0*n*(n-1));
end intrinsic;

intrinsic Indices(W::CryptTxt,C::MonStgElt) -> SeqEnum
    {}
    return Indices(String(W),C);
end intrinsic;

intrinsic Indices(W::MonStgElt,C::MonStgElt) -> SeqEnum
    {}
    N := #W;
    k := #C;
    S := [ Integers() | ];
    for i in [1..N-k+1] do
        if C eq Substring(W,i,k) then
            Append(~S,i);
        end if;
    end for;
    return S;
end intrinsic;

intrinsic Multiplicity(S::MonStgElt,W::MonStgElt) -> RngIntElt
    {}
    n := #W;
    return &+[ 1 : i in [1..#S+1-n] | Substring(S,i,n) eq W ];
end intrinsic;

intrinsic Decimation(S::MonStgElt,k::RngIntElt,n::RngIntElt)
    -> MonStgElt
    {}
    k := k mod n;
    if k eq 0 then k := n; end if;
    S := StripEncoding(S : WildCharacter := "*");
    return &cat[ S[n*i+k] : i in [0..(#S div n)-1] ];
end intrinsic;

intrinsic Decimation(
    S::MonStgElt,P::[RngIntElt],n::RngIntElt) -> MonStgElt
    {}
    require #P le n :
        "Argument 2 must have length at most that of argument 3.";
    i, j := Explode(P);
    require i ne j :
        "Argument 2 must represent distinct congruence classes.";
    require n gt 0 : "Argument 3 must be positive.";
    i := ((i-1) mod n) + 1;
    j := ((j-1) mod n) + 1;
    if i eq 0 then i := n; end if;
    if j eq 0 then j := n; end if;
    S := StripEncoding(S : WildCharacter := "*");
    return [ &cat[ S[n*k+i] : i in P ] : k in [0..(#S div n)-1] ];
end intrinsic;

intrinsic CoincidenceIndex(S::SeqEnum) -> FldReElt
    {}
    n := #S; 
    Freq := [ RealField() | ];
    for X in SequenceToSet(S) do
        Append(~Freq,#[ i : i in [1..n] | S[i] eq X ]); 
    end for;
    return &+[ f*(f-1) : f in Freq ]/(1.0*n*(n-1));
end intrinsic;

intrinsic DecimationFrequencies(
    S::MonStgElt,P::[RngIntElt],n::RngIntElt) -> MonStgElt
    {}
    require #P eq 2 : "Argument 2 must have length 2.";
    i, j := Explode(P);
    require i ne j :
        "Argument 2 must represent distinct congruence classes.";
    require n gt 0 : "Argument 3 must be positive.";
    i := i mod n;
    j := j mod n;
    if i eq 0 then i := n; end if;
    if j eq 0 then j := n; end if;
    S := StripEncoding(S : WildCharacter := "*");
    RR := RealField();
    M := MatrixAlgebra(RR,26)!0;
    for k in [0..(#S div n)-1] do
        M[Index(Alphabet,S[n*k+i]),Index(Alphabet,S[n*k+j])] +:= 1;
    end for;
    return M/(1.0*(#S div n));
end intrinsic;

intrinsic DecimationFrequency(CT::MonStgElt,W::MonStgElt,
    i::RngIntElt,m::RngIntElt) -> SeqEnum
    {}
    require #W eq 1 : "Argument 2 must have length 1.";
    return DecimationFrequency(CT,W,[i],m);
end intrinsic;

intrinsic DecimationFrequency(CT::MonStgElt,W::MonStgElt,
    I::[RngIntElt],m::RngIntElt) -> SeqEnum
    {}  
    require #W eq #I: "Argument 2 and 3 must have the same length.";
    require &and[ i in {1..m} : i in I ] : 
        "Elements of argument 3 must in the set {1..m}."; 
    n := (#CT div m) - 1;
    f := 0;
    for j in [1..n] do
        X := &cat[ CT[i+m*j] : i in I ];
        if X eq W then
            f +:= 1;    
        end if;         
    end for;  
    return 1.0*f/n;
end intrinsic;

intrinsic TranspositionHighFrequencyMatches( 
    CT::MonStgElt, W::MonStgElt, m::RngIntElt, r::FldReElt) -> SeqEnum
    {Transposition frequency matches.}

    require r gt 1 : "Argument 4 must be greater than 1.";
    G := SymmetricGroup(#W);
    Matches := [ Parent(<[0],r>) | ];
    freqs := [ [ DecimationFrequency(CT,W[i],j,m) 
                 : j in [1..m] ] : i in [1..#W] ];
    for I in Subsequences([1..m],#W) do                        
        F := [ DecimationFrequency(CT,W[k],[I[k]],m) : k in [1..#W] ];
        for g in G do
            J := [ I[i^g] : i in [1..#W] ];
            E := &*[ freqs[i][J[i]] : i in [1..#W] ];
            if E ne 0 then
                f := DecimationFrequency(CT,W,J,m)/E;         
                // vprintf Crypto : "%o: %o\n", J, f;
                if f gt r then
                    Append(~Matches,<J,f>);
                end if;
            end if;
        end for;
    end for;  
    return Matches;
end intrinsic;

function ReductionIndices(I,m)
   return [ ((i-1) mod m)+1 : i in I ];
end function;

procedure MergeCountReduction(~IdxSeq,~IdxCnt,T,m)
    for I in T do
        J := ReductionIndices(I,m);
        k := Index(IdxSeq,J);
        if k eq 0 then
            Append(~IdxSeq,J);
            Append(~IdxCnt,1);
        else 
            IdxCnt[k] +:= 1;
        end if; 
    end for;        
end procedure;

intrinsic TranspositionMatches(
    CT::MonStgElt,StrSeq::[MonStgElt],m::RngIntElt) -> SeqEnum, SeqEnum
    {}
    r := #StrSeq[1];
    error if &or[ #StrSeq[i] ne r : i in [1..#StrSeq] ],
        "Sequence must consist of strings of the same length.";
    IdxSeq := [ Parent([0]) | ];
    IdxCnt := [ Integers() | ];
    for X in StrSeq do
        T := TranspositionIndexMatches(CT,X,m);
        MergeCountReduction(~IdxSeq,~IdxCnt,T,m);
    end for;
    return IdxSeq, IdxCnt;
end intrinsic;

intrinsic TranspositionIndexMatches(
    CT::MonStgElt, W::MonStgElt, m::RngIntElt) -> SeqEnum
    {Returns the sequence of indices I = [i_1,i_2,...,i_n] such that
    each i_j is between m*k + 1 and m*(k+1) for some k, and W is equal
    to &cat[ CT[i_j] : j in [1..n] ].  The second return argument is
    a sequence of tuples consisting of a representative for the indices
    I with i_j between 1 and m and the count of its multiplicity.}

    r := #W;
    require r gt 1: "Argument 2 must have length at least 2.";
    chars := SetToSequence({ W[i] : i in [1..r] });
    n := (#CT div m) - 1;
    freqw := [ 0 : i in [1..#chars] ];
    for i in [1..r] do
        freqw[Index(chars,W[i])] +:= 1;
    end for;
    Matches := [ Parent([0]) | ];
    for j in [0..n] do
        freqs := [ 0 : i in [1..#chars] ];
        indsj := [ [] : i in [1..#chars] ];
        for i in [1..m] do
            k := Index(chars,CT[m*j+i]);
            if k ne 0 then
               freqs[k] +:= 1;
               Append(~indsj[k],m*j+i); 
           end if;            
        end for; 
        if &and[ freqs[i] ge freqw[i] : i in [1..#chars] ] then
            nchar := [ freqs[Index(chars,W[i])] : i in [1..r] ];
            indsw := [ indsj[Index(chars,W[i])] : i in [1..r] ];
            for t in [0..&*nchar-1] do
                s := t;
                I := [ Integers() | ];
                for i in [1..r] do
                    Append(~I,(s mod nchar[i])+1);
                    s div:= nchar[i];
                end for;
                J := [ indsw[i][I[i]] : i in [1..r] ];
                assert &cat [ CT[x] : x in J ] eq W;
                if #SequenceToSet(J) eq r then
                    Append(~Matches,J);
                end if;
            end for;
        end if;
    end for;     
    MSeq := [ [ ((I[i]-1) mod m)+1 : i in [1..r] ] : I in Matches ];
    MSet := SequenceToSet(MSeq);
    MCounts := [
        <I,#[ i : i in [1..#MSeq] | MSeq[i] eq I ]> : I in MSet ];
    return Matches, MCounts;
end intrinsic;


intrinsic CoincidenceDiscriminant(S::[MonStgElt] : 
    Precision := 19) -> FldReElt
    {The coincidence discrimiant of the 2-character sequence S.}
    AA := {@ A*B : A, B in AZ @} where  
        AZ := [ CodeToString(64+i) : i in [1..26] ];
    cnts := [ 0 : i in [1..26^2] ];
    for s in S do
        cnts[Index(AA,s)] +:= 1;
    end for;
    F1 := FrequencyDistribution(
        &*[ s[1] : s in S ] : Precision := Precision);
    F2 := FrequencyDistribution(
        &*[ s[2] : s in S ] : Precision := Precision);
    RR := RealField(Precision);    
    return RealField() !
        &+[ (RR!cnts[i+26*(j-1)]/#S-F1[i]*F2[j])^2 : i, j in [1..26]];
end intrinsic;

intrinsic CoincidenceIndex(S::MonStgElt,j::RngIntElt :
    Precision := 19) -> FldReElt
    {}
    require j eq 2 : "Argument 2 must be 2";
    Alph := [ CodeToString(64+i) : i in [1..26] ];
    AA := {@ A*B : A, B in Alph @}; 
    FD := FrequencyDistribution(S : Precision := Precision);
    cnts := [ 0 : i in [1..26^2] ];
    for i in [1..#S-1] do
        cnts[Index(AA,S[i]*S[i+1])] +:= 1;
    end for;
    RR := RealField();    
    RX := RealField(Precision);    
    return &+[ RR | (RX!cnts[i+26*(j-1)]/(#S-1))^2 : i, j in [1..26] ];
end intrinsic;

////////////////////////////////////////////////////////////////////////
//                                                                    // 
//                        MAGMA STRING ENCODING                       // 
//                             David Kohel                            //
//                            February 2001                           //
//                                                                    // 
//////////////////////////////////////////////////////////////////////// 

ALPHABET := ["A","B","C","D","E","F","G","H","I","J","K","L","M",
             "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]; 
alphabet := ["a","b","c","d","e","f","g","h","i","j","k","l","m",
             "n","o","p","q","r","s","t","u","v","w","x","y","z"]; 

intrinsic RandomSubstitutionKey() -> MonStgElt
    {Returns a string which is a random permutation of the characters
    A through Z, all upper case.}
    S := ALPHABET;
    X := "";
    for i in [1..#S] do
        c := Random(S);
        X cat:= c;
        Exclude(~S,c);
    end for;
    return X;
end intrinsic;

intrinsic SubstitutionEnciphering(K::MonStgElt,W::MonStgElt :
    Encode := true) -> MonStgElt
    {Given a 26 character key K and a plaintext file W, each over
    the alphabet A...Z, return the substitution ciphertext for W
    defined by the simple substitution key K.}
        
    if Encode then
        K := StripEncoding(K);
        W := StripEncoding(W);
    end if;
    require #K eq 26 : "Invalid substitution key."; 
    n := #W;
    I := [ i eq -22 select 27 else i
        where i := StringToCode(W[i])-64 : i in [1..n] ];
    K cat:= "*";
    return &cat[ I[i] eq -54 select "\n" else K[I[i]] : i in [1..n] ];
end intrinsic;

intrinsic SubstitutionEnciphering(A::SetIndx,K::SetIndx,W::MonStgElt) -> MonStgElt
    {Given an alphabet A, a key K of the same length, and a plaintext file W
    over A, return the substitution ciphertext for W  defined by K.}
        
    //K := StripEncoding(K);
    //W := StripEncoding(W);
    require #K eq #A :
        "Arguments 1 and 2 must have the same length.";
    require Type(Universe(A)) eq MonStg and Type(Universe(K)) eq MonStg : 
        "Arguments 1 and 2 must be indexed sets of strings.";
    C := "";
    I := [ Index(K,W[i]) : i in [1..#W] ]; 
    return &cat[ I[i] ne 0 select A[I[i]] else W[i] : i in [1..#I] ];
end intrinsic;

intrinsic StripEncoding(W::MonStgElt :
    LineLength := 0, WildCharacter := "") -> MonStgElt
    {Returns the string generated from W by discarding all non-alphabetic
    characters and changing all remaining characters to upper case.}
    require LineLength ge 0 :
        "Parameter LineLength must be non-negative.";
    newline := "\n";
    X := "";
    j := 0;
    for i in [1..#W] do
        c := W[i];
        if c in ALPHABET then
            X cat:= c;
            j +:= 1;
            if LineLength ne 0 and j mod LineLength eq 0 then
                X cat:= newline;
            end if;
        elif c in alphabet then
            X cat:= ALPHABET[Index(alphabet,c)];
            j +:= 1;
            if LineLength ne 0 and j mod LineLength eq 0 then
                X cat:= newline;
            end if;
        elif c eq WildCharacter then
            X cat:= c;
            j +:= 1;
        end if;
    end for;
    return X;
end intrinsic;

function ByteBits(n)
    S := [ Integers() | ];
    for i in [1..8] do
        Append(~S,n mod 2);
        n div:= 2;
    end for;
    return Reverse(S);
end function;

intrinsic BitEncoding(W::MonStgElt) -> SeqEnum
    {The sequence of bits (over FiniteField(2)) encoding the string W.}
    S := &cat[ ByteBits(StringToCode(W[i])) : i in [1..#W] ];
    return ChangeUniverse(S,GF(2));
end intrinsic;

intrinsic BitDecoding(S::SeqEnum) -> SeqEnum
    {The ASCII string represented by the bit sequence S.}
    N := #S;
    // require N mod 8 eq 0 : "Argument must have length divisible by 8.";
    require Universe(S) eq GF(2) :
        "Argument must be a sequence of the field of 2 elements.";
    ChangeUniverse(~S,Integers());
    Word := "";
    for j in [0..(N div 8)-1] do
        n := 0;
        for i in [1..8] do
            n +:= S[8*j+i]*2^(8-i);
        end for;
        if n eq 0 then break; end if;
        Word cat:= CodeToString(n);
    end for;
    return Word;
end intrinsic;



