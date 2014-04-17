void pre_order(TreeNode* root) {
	if (root != NULL) {
		cout << root->data << endl;
		pre_order(root->left);
		pre_order(root->right);
	}
}

void mid_order(TreeNode* root) {
	if (root) {
		mid_order(root->left);
		cout << root->data << endl;
		mid_order(root->right);
	}
}

void pre_order2(TreeNode* root) {
	Stack<TreeNode*> stack;
	TreeNode* p = root;
	while (p || !stack.empty()) {
		while (p) {
			cout << p->data << endl;
			stack.push(p);
			p = p->left;
		}
		if (!stack.empty()) {
			p = stack.top();
			stack.pop();
			p = p->right;
		}
	}
}

void mid_order2(TreeNode* root) {
	stack<TreeNode*> stack;
	TreeNode* p = root;
	while (p || !stack.empty()) {
		while (p) {
			stack.push(p);
			p = p->left;
		}
		if (!stack.empty()) {
			p = stack.top();
			cout << p->data << endl;
			stack.pop();
			p = p->right;
		}
	}
}

void post_order2(TreeNode* root) {
	stack<TreeNode*> stack;
	if (root)
		stack.push(root);
	while (!stack.empty()) {
		TreeNode* pcur = stack.pop();
		if ((pcur->left == NULL && pcur->right == NULL) ||
				(ppre && (ppre == pcur->left || ppre == pcur->right))) {
			cout << ppcur->data << endl;
			stack.pop();
			ppre = pcur;
		} else {
			if (pcur->right)
				stack.push(pcur->right);
			if (pcur->left)
				stack.push(pcur->left);
		}
	}
}
