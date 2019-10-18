helpFunction()
{
   echo ""
   echo "Usage: $0 -r rivalName -m mapIndex -o 1"
   echo -r "\tFile of rival. Examples: abanlin, carli, champely, grati, hcao, superjeannot"
   echo -m "\tShows the scale of map. Examples: 0, 1, 2"
   echo -o "\tOrder. Examples: O - you are first, X - you are second"
   exit 1 # Exit script after printing help
}

while getopts "r:m:o:" opt
do
   case "$opt" in
      r ) rivalName="$OPTARG" ;;
      m ) mapIndex="$OPTARG" ;;
	  o ) order="$OPTARG" ;;
      ? ) helpFunction ;; # Print helpFunction in case parameter is non-existent
   esac
done

# Print helpFunction in case parameters are empty
if [ -z "$rivalName" ] || [ -z "$mapIndex" ]  || [ -z "$order" ] 
then
   echo "Some or all of the parameters are empty";
   helpFunction
fi

# Print helpFunction in case parameters are wrong
case $rivalName in
	abanlin|carli|champely|grati|hcao|superjeannot)
		;;
	*)
		echo "Rival name has wrong spelling";
		helpFunction
esac
case $mapIndex in
	0|1|2)
		;;
	*)
		echo "Map does not exist";
		helpFunction
esac

make
case $order in
	O)
		./resources/filler_vm -p1 ./ilian.filler -p2 resources/players/$rivalName.filler -v -f resources/maps/map0$mapIndex
		;;
	X)
		./resources/filler_vm -p2 ./ilian.filler -p1 resources/players/$rivalName.filler -v -f resources/maps/map0$mapIndex
		;;
	*)
		echo "Order is wrong";
   		helpFunction
esac