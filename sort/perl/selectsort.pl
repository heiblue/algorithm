#!/usr/bin/perl
#
#
#@list = (3,6,7,1,5,9,8,2,4);
@list = (43,5,3,4,5543,3,4,64,3,6,7,86,5,8,6875);

for($i = o; $i < @list; $i++){
		$min = $i;
	for($j = $i; $j < @list; $j++){
		if($list[$j] < $list[$min]){
			$min = $j;		
		}
	}
	($list[$i], $list[$min]) = ($list[$min], $list[$i]);
}


foreach $x(@list){
	print "$x ";
}
print "\n";
