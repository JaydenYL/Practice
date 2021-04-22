for i in {226..255}
do
	for j in {32..255}
	do
		HOST=10.86.$i.$j
		ping -c 2 $HOST &>/dev/null
		if [ $? -eq 0 ];then
			echo "$HOST is OK" >> ip_used.txt
		else
			echo "$HOST is NO USED" >> ip_not_used.txt
		fi
	done
done