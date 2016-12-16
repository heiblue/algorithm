#!/usr/bin/perl
#
#
use strict;

my ($source, $target) = ("source", "ce");

sub yjstrStr($$){
	my ($s, $t) = @_;
	if(undef($s) || undef($t)){
		return -1;
	}
	my @src = split("",$s);
	my @tgr = split("",$t);

	my ($slen, $tlen) = (@src, @tgr);	
	my ($i, $j) = (0, 0);
	for($i; $i < $slen-$tlen+1; $i++){
		for($j; $j < $tlen; $j++){
			if($src[$i+$j] != $tgr[$j]){
				last;
			}
			if($j == $tlen){
				return $i;
			}
		}
	}
	return -1;

}

print &yjstrStr($source, $target);
