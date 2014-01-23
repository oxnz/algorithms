# Address
# 		This package defines an address object.

package Address;

# Create a new address. Extra arguments are stored in the object:
# $address = new Address(name => "Wolf Blass", country => "Australia" ...
#

sub new {
	my $package = shift;
	my $self = { @_ };
	return bless $self, $package;
}

# The country method gets and sets the country field.
#
sub country {
	my $self = shift;
	return @_ ? ($self->{country} = shift) : $self->{country};
}

# The methods for zone, city, street, and name
#
sub zone {
	my $self = shift;
	return @_ ? ($self->{zone} = shift) : $self->{zone};
}

sub city {
	my $self = shift;
	return @_ ? ($self->{city} = shift) : $self->{city};
}

sub street {
	my $self = shift;
	return @_ ? ($self->{street} = shift) : $self->{street};
}

sub name {
	my $self = shift;
	return @_ ? ($self->{name} = shift) : $self->{name};
}

# The as_string() method
sub as_string {
	my $self = shift;
	my $string;

	foreach (qw(name street city zone country)) {
		$string .= "$self->{$_}\n" if defined $self->{$_};
	}
	return $string;
}
