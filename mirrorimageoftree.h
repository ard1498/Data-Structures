void mirrorimage(const tree& t1){
        tree t2 = t1;
        nodeswap(t2.root);
        t2.printarr();
        return;
    }

    void nodeswap(node* root){
        if(root == NULL){
            return;
        }
        else{
            node * temp = root->leftnode;
            root->leftnode = root->rightnode;
            root->rightnode = temp;
            nodeswap(root->leftnode);
            nodeswap(root->rightnode);
        }
    }