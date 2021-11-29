166,0
S,RSACryptosystem,"The RSA cryptosystem of block length m bits, and moduli
S,RandomKeys,"Given an RSA cryptosystem, generates an RSA public-private key
S,IsPublicPrivatePair,"Given two RSA keys K and L, returns true if and only
S,RSAExponent,,0,1,0,0,0,0,0,0,0,CryptKey,,148,-38,-38,-38,-38
S,RSAModulus,,0,1,0,0,0,0,0,0,0,CryptKey,,148,-38,-38,-38,-38
V,Crypt,2
T,Crypt,-,0
T,CryptKey,-,0
A,Crypt,5,CipherType,IsSymmetric,BlockLength,Domain,Codomain
S,SubstitutionCryptosystem,,0,0,0,0,0,0,0,Crypt,-38,-38,-38,-38
S,SubstitutionCryptosystem,,0,1,0,0,0,0,0,0,0,151,,Crypt,-38,-38,-38,-38
S,TranspositionCryptosystem,,0,1,0,0,0,0,0,0,0,148,,Crypt,-38,-38,-38,-38
S,VigenereCryptosystem,The Vigenere cryptosystem of block length m,0,1,0,0,0,0,0,0,0,148,,Crypt,-38,-38,-38,-38
S,LFSRCryptosystem,The linear feedback shift register cryptosystem,0,0,0,0,0,0,0,Crypt,-38,-38,-38,-38
S,ShrinkingGeneratorCryptosystem,"The shrinking generator cryptosystem, based on a pair of
S,IsCoercible,,0,2,0,0,0,0,0,0,0,-1,,0,0,Crypt,,36,298,-38,-38,-38
S,RandomKey,,0,1,0,0,0,0,0,0,0,Crypt,,CryptKey,-38,-38,-38,-38
S,Print,,0,2,0,0,1,0,0,0,0,298,,0,0,Crypt,,-38,-38,-38,-38,-38
S,eq,,0,2,0,0,0,0,0,0,0,Crypt,,0,0,Crypt,,36,-38,-38,-38,-38
S,Decoding,"Given cryptographic text, return the associated decoded string.
S,Encoding,"Given a message text W, encode the message in the domain of 
S,Encoding,"Given a binary message text W, encode the message for
S,Deciphering,,0,2,0,0,0,0,0,0,0,CryptTxt,,0,0,CryptKey,,298,-38,-38,-38,-38
S,Enciphering,,0,2,0,0,0,0,0,0,0,CryptTxt,,0,0,CryptKey,,298,-38,-38,-38,-38
S,CipherType,The string identifying the cryptographic algorithm of C,0,1,0,0,0,0,0,0,0,Crypt,,298,-38,-38,-38,-38
S,BlockLength,The string identifying the cryptographic algorithm of C,0,1,0,0,0,0,0,0,0,Crypt,,298,-38,-38,-38,-38
S,DomainAlphabet,,0,1,0,0,0,0,0,0,0,Crypt,,82,-38,-38,-38,-38
S,CodomainAlphabet,,0,1,0,0,0,0,0,0,0,Crypt,,82,-38,-38,-38,-38
A,CryptKey,5,Parent,IsEnciphering,KeyString,ConnectionPolynomial,InitialState
S,Print,,0,2,0,0,1,0,0,0,0,298,,0,0,CryptKey,,-38,-38,-38,-38,-38
S,eq,,0,2,0,0,0,0,0,0,0,CryptKey,,0,0,CryptKey,,36,-38,-38,-38,-38
S,Parent,,0,1,0,0,0,0,0,0,0,CryptKey,,Crypt,-38,-38,-38,-38
S,String,"The string -- (usually, but not always) of type MonStgElt --
S,InverseKey,The inverse key of a symmetric cryptosystem,0,1,0,0,0,0,0,0,0,CryptKey,,CryptKey,-38,-38,-38,-38
T,CryptTxt,-,0
A,CryptTxt,3,Cryptosystem,IsPlainText,String
S,Print,,0,2,0,0,1,0,0,0,0,298,,0,0,CryptTxt,,-38,-38,-38,-38,-38
S,eq,,0,2,0,0,0,0,0,0,0,CryptTxt,,0,0,CryptTxt,,36,-38,-38,-38,-38
S,Cryptosystem,The cryptosytem of W,0,1,0,0,0,0,0,0,0,CryptTxt,,Crypt,-38,-38,-38,-38
S,String,The key string -- of type MonStgElt -- the cryptogrphic key,0,1,0,0,0,0,0,0,0,CryptTxt,,298,-38,-38,-38,-38
S,IsPlainText,Returns true if and only if W is plaintext,0,1,0,0,0,0,0,0,0,CryptTxt,,Crypt,-38,-38,-38,-38
S,IsCipherText,Returns true if and only if W is ciphertext,0,1,0,0,0,0,0,0,0,CryptTxt,,Crypt,-38,-38,-38,-38
S,TranslationCorrelations,The sequence of correlations of the sequence S1 with the 
S,TranslationMatches,,1,1,1,82,0,402,3,0,0,0,0,0,0,0,402,,0,0,82,,0,0,298,,82,-38,-38,-38,-38
S,Frequency,"The number of occurrences of a string W in the ciphertext CT 
S,Frequency,"The number of occurrences of a string W in the ciphertext CT 
S,FrequencyDistribution,,0,1,0,0,0,0,0,0,0,CryptTxt,,82,-38,-38,-38,-38
S,FrequencyDistribution,,0,1,0,0,0,0,0,0,0,298,,82,-38,-38,-38,-38
S,FrequencyDistribution,,0,1,0,0,0,0,0,0,0,CryptTxt,,82,-38,-38,-38,-38
S,DigraphFrequencyDistribution,,0,1,0,0,0,0,0,0,0,CryptTxt,,82,-38,-38,-38,-38
S,DigraphFrequencyDistribution,The number of occurrences of a character C in the string W,0,1,0,0,0,0,0,0,0,298,,177,-38,-38,-38,-38
S,PolygraphFrequencyDistribution,"The indexed set of substrings of length n occurring with frequency
S,CoincidenceIndex,,0,1,0,0,0,0,0,0,0,CryptTxt,,402,-38,-38,-38,-38
S,CoincidenceIndex,,0,1,0,0,0,0,0,0,0,298,,402,-38,-38,-38,-38
S,Indices,,0,2,0,0,0,0,0,0,0,298,,0,0,CryptTxt,,82,-38,-38,-38,-38
S,Indices,,0,2,0,0,0,0,0,0,0,298,,0,0,298,,82,-38,-38,-38,-38
S,Multiplicity,,0,2,0,0,0,0,0,0,0,298,,0,0,298,,148,-38,-38,-38,-38
S,Decimation,,0,3,0,0,0,0,0,0,0,148,,0,0,148,,0,0,298,,298,-38,-38,-38,-38
S,Decimation,,1,1,1,82,0,148,3,0,0,0,0,0,0,0,148,,0,0,82,,0,0,298,,298,-38,-38,-38,-38
S,CoincidenceIndex,,0,1,0,0,0,0,0,0,0,82,,402,-38,-38,-38,-38
S,DecimationFrequencies,,1,1,1,82,0,148,3,0,0,0,0,0,0,0,148,,0,0,82,,0,0,298,,298,-38,-38,-38,-38
S,DecimationFrequency,,0,4,0,0,0,0,0,0,0,148,,0,0,148,,0,0,298,,0,0,298,,82,-38,-38,-38,-38
S,DecimationFrequency,,1,2,1,82,0,148,4,0,0,0,0,0,0,0,148,,0,0,82,,0,0,298,,0,0,298,,82,-38,-38,-38,-38
S,TranspositionHighFrequencyMatches,Transposition frequency matches,0,4,0,0,0,0,0,0,0,402,,0,0,148,,0,0,298,,0,0,298,,82,-38,-38,-38,-38
S,TranspositionMatches,,1,1,1,82,0,298,3,0,0,0,0,0,0,0,148,,0,0,82,,0,0,298,,82,82,-38,-38,-38
S,TranspositionIndexMatches,"Returns the sequence of indices I = [i_1,i_2,...,i_n] such that
S,CoincidenceDiscriminant,The coincidence discrimiant of the 2-character sequence S,1,0,1,82,0,298,1,0,0,0,0,0,0,0,82,,402,-38,-38,-38,-38
S,CoincidenceIndex,,0,2,0,0,0,0,0,0,0,148,,0,0,298,,402,-38,-38,-38,-38
S,RandomSubstitutionKey,"Returns a string which is a random permutation of the characters
S,SubstitutionEnciphering,"Given a 26 character key K and a plaintext file W, each over
S,SubstitutionEnciphering,"Given an alphabet A, a key K of the same length, and a plaintext file W
S,StripEncoding,Returns the string generated from W by discarding all non-alphabetic
S,BitEncoding,The sequence of bits (over FiniteField(2)) encoding the string W,0,1,0,0,0,0,0,0,0,298,,82,-38,-38,-38,-38
S,BitDecoding,The ASCII string represented by the bit sequence S,0,1,0,0,0,0,0,0,0,82,,82,-38,-38,-38,-38