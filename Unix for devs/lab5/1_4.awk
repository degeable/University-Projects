BEGIN {FS=",";ctr=0;} #to spereate the head words
{
if (substr($1, 1, 1) == "#")
	{
	word1=substr($1, 2) # we now need 4 words to get all the head information
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
	} 
}
END{print "\nend of file:" FILENAME " Total lines: " FNR;}

function header(){
	printf("\n\n %32s %30s %30s %30s \n\n",word1,word2,word3,word4);
}

