begin=223
wid=1
end=`expr $begin + $wid - 1`
 
for i in `seq $begin $end`
do
   for j in `seq 0 255`
   do
       HOST=10.86.$i.$j
       ping -c 2 $HOST &>/dev/null
       if [ $? -eq 0 ];then
           echo "$HOST is OK" >> used_$begin.txt
       else
           echo "$HOST is NO USED" >> not_used_$begin.txt
       fi
   done
done

