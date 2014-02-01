#!/usr/bin/env perl
# upper case impl in 3 approach

use strict;
use warnings;
use integer;

@uppers = map { uc chr } (0..127); # Our lookup array

# Our lookup hash
%uppers = (' ', ' ', '!', '!', qw!" " # # $ $ % % & & ' ' ( ( ) ) * * + + ,
	, - - . . / / 0 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 : : ; ; < <
	= = > > ? ? @ @ A A B B C C D D E E F F G G H H I I J J K K L L M M
	N N O O P P Q Q R R S S T T U U V V W W X X Y Y Z Z [ [ \ \ ] ]
	^ ^ _ _ ` ` a A b B c C d D e E f F g G h H i I j J k K l L m M n
	N o O p P q Q r R s S t T u U v V w W x X y Y z Z { { | | } } ~ ~ !
);

sub compute { # Approach 1: direct computation
	my $c = ord $_[0];
	$c -= 32 if $c >= 97 and $c <= 122;
	return chr($c);
}

sub lookup_array { # Approach 2: the lookup array
	return $uppers[ ord( $_[0] ) ];
}

sub lookup_hash { # Approach 3: the lookup hash
	return $uppers{ $_[0] };
}
