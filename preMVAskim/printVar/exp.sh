vars=`cat list`
#echo $vars
for var in $vars
do
#	echo new_${var}\[i\] = ${var}\[j\]\;
	echo "treeIn->SetBranchAddress(\"${var}\", ${var});"
done
