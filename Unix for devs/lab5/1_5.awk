BEGIN {
	FS=",";
	ctr=0;
	totalPopulation=0;
	mostCitizens=0;
	fewestCitizens=1000000;
	mostCapitals=0;
	continentWithMostCapitals="";
	biggestCity="";
	smallestCity="";
}

{
if (substr($1, 1, 1) == "#")
		{
		word1=substr($1, 2)
		word2=$2 
		word3=$3 
		word4=$4
		header();
		}
else

		{
		ctr++;
		if (ctr % 30 == 0)
			header();
		printf("%32s %30s %30s %30s \n",$1 ,  $2 ,  $3 , $4);
		
		totalPopulation+=$2;
	
		if(FNR == 1){ # just take first capital as smallest
			fewestCitizens=$2;
			smallestCity=$3;
		}
	
		if(fewestCitizens>$2 && $3 !=""){ # simple comparison
			fewestCitizens=$2;
			smallestCity=$3;
		}
	
		if(mostCitizens<$2){ 
			mostCitizens=$2;
			biggestCity=$3;
		}
	
	    if(capitalsInContinent[$4]==""){# Associative array. at first its empty ("") so we set it to 0 
			capitalsInContinent[$4]=0;
		}
		capitalsInContinent[$4]++; # and increment 

		if(citizensInContinent[$4]==""){ # same as capitals in continents
			citizensInContinent[$4]=0;
		}
		citizensInContinent[$4]+=$2; # add citizens on top


		
		
		} 
}

END	{
print "\nend of file:" FILENAME " Total lines: " FNR " Total Population: " totalPopulation "\n\n";
print "Biggest city: " biggestCity " with " mostCitizens " citizen.\n"
print "Smallest city: " smallestCity " with " fewestCitizens " citizen.\n"
for (continent in capitalsInContinent){ # compare all contitents with their amount of capitals
     if(capitalsInContinent[continent]>mostCapitals){
	 	mostCapitals=capitalsInContinent[continent];
		continentWithMostCapitals=continent;
		}

	}	
print("Continent with most capitals: " continentWithMostCapitals "("mostCapitals")\n");	# print the one with the most


for (continent in citizensInContinent){
		printf(continent " -> " citizensInContinent[continent]"\n");
	}

 		}

function header(){
	printf("\n\n %32s %30s %30s %30s \n\n",word1,word2,word3,word4);
}

