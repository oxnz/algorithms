#include "tree.h"

using namespace std;

int main(int argc, char *argv[]) {
	Tree *t = new Tree();
	t->insert(Data(1.2));
	t->insert(Data(0.8));
	t->insert(Data(1.7));
	delete t;
	return 0;
}
