#include <iostream>
using namespace std;

// node
struct Node{
  char label;
  Node *left, *right, *parent;
};

// variabel pointer global
Node *root, *newNode;

// create New Tree
void createNewTree( char label )
{

  if( root != NULL )
    cout << "\nTree sudah dibuat" << endl;
  else{
    root = new Node();
    root->label = label;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\nNode " << label << " berhasil dibuat menjadi root." << endl;
  }

}

// insert Left
Node *insertLeft( char label, Node *node )
{
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->left != NULL ){
      // kalau ada
      cout << "\nNode "<< node->label << " sudah ada anak kiri!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
      return newNode;
    }

  }
}

// insert right
Node *insertRight( char label, Node *node )
{
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->right != NULL ){
      // kalau ada
      cout << "\nNode " << node->label << " sudah ada anak kanan!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;
      cout << "\nNode" << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
      return newNode;
    }

  }
}

// Empty
bool empty()
{
  if( root == NULL )
    return true;
  else
    return false;
}

// update
void update(char label, Node *node)
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ingin diganti tidak ada!!" << endl;
    else{
      char temp = node->label;
      node->label = label;
      cout << "\nLabel node " << temp << " berhasil diubah menjadi " << label << endl;
    }
  }
}

// retrieve digunakan untuk mengambil informasi dari suatu node yang ditunjuk
void retrieve( Node *node )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else{
      cout << "\nLabel node : " << node->label << endl;
    }
  }
}

// Find  bdigunakan untuk mencari informasi terkait dengan suatu node yang ditunjuk
void find( Node *node )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else{


      cout << "\nLabel Node : " << node->label << endl;
      cout << "Root Node : " << root->label << endl;
      
      if( !node->parent )
        cout << "Parent Node : (tidak punya orang tua)" << endl;
      else
        cout << "Parent Node : " << node->parent->label << endl;



      if( node->parent != NULL && node->parent->left != node && node->parent->right == node )

        cout << "Saudara : " << node->parent->left->label << endl;

      else if( node->parent != NULL && node->parent->right != node && 
      node->parent->left == node )

        cout << "Saudara : " << node->parent->right->label << endl;

      else

        cout << "Saudara : (tidak punya saudara)" << endl;




      if( !node->left )
        cout << "Anak Kiri Node : (tidak punya anak kiri)" << endl;
      else
        cout << "Anak Kiri Node : " << node->left->label << endl;

      if( !node->right )
        cout << "Anak Kanan Node : (tidak punya anak kanan)" << endl;
      else
        cout << "Anak Kanan Node : " << node->right->label << endl;



    }
    

  }
}

// Tranversal
// preOrder
void preOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      cout << node->label << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }

  }

}

// inOrder
void inOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      inOrder(node->left);
      cout << node->label << ", ";
      inOrder(node->right);
    }

  }

}

// postOrder
void postOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout << node->label << ", ";
    }

  }

}

// deleteTree
void deleteTree( Node *node )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      if( node != root ){
        node->parent->left = NULL;
        node->parent->right = NULL;
      }
      deleteTree(node->left);
      deleteTree(node->right);
      
      if( node == root ){
        delete root;
        root = NULL;
      }else{
        delete node;
      }

    }

  }

}

// delete Sub
void deleteSub(Node *node){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    deleteTree(node->left);
    deleteTree(node->right);
    cout << "\nSubtree node " << node->label << " berhasil dihapus."  << endl;
  }
}

// clear
void clear(){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    deleteTree(root);
    cout << "\nTree berhasil dihapus."  << endl;
  }
}


// size
int size(Node *node = root){
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
  }else{

    if( !node ){
      return 0;
    }else{
      return 1 + size( node->left ) + size(node->right);
    }

  }
}

// height
int height( Node *node = root )
{
  if( !root ){
      cout << "\nBuat tree terlebih dahulu!!" << endl;
      return 0;
    }else{
      if( !node ){
        return 0;
      }else{
        int heightKiri = height( node->left );
        int heightKanan = height( node->right );

        if( heightKiri >= heightKanan ){
          return heightKiri + 1;
        }else{
          return heightKanan + 1;
        }

      }
    }
}

// characteristic
void charateristic()
{
  cout << "\nSize Tree : " << size() << endl;
  cout << "Height Tree : " << height() << endl;
  cout << "Average Node of Tree : " << size() / height() << endl;
}




int main()
{
  // Membuat pohon baru dengan node A sebagai root
  createNewTree('A');

  // Membuat node-node lainnya dan menghubungkannya dengan node-node yang sudah ada
  Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

  nodeB = insertLeft('B', root);
  nodeC = insertRight('C', root);
  nodeD = insertLeft('D', nodeB);
  nodeE = insertRight('E', nodeB);
  nodeF = insertLeft('F', nodeC);
  nodeG = insertLeft('G', nodeE);
  nodeH = insertRight('H', nodeE);
  nodeI = insertLeft('I', nodeG);
  nodeJ = insertRight('J', nodeG);

  // Menampilkan apakah pohon kosong atau tidak
  cout << "Tree empty? : " << empty() << endl;

  // Mengupdate label node C menjadi Z, kemudian mengubahnya kembali menjadi C
  update('Z', nodeC);
  update('C', nodeC);

  // Menampilkan label node C
  retrieve(nodeC);

  // Menampilkan informasi tentang node C dan hubungannya dengan node lainnya
  find(nodeC);

  // Menampilkan traversal PreOrder, InOrder, dan PostOrder dimulai dari node E
  cout << "\nPreOrder :" << endl;
  preOrder(nodeE);
  cout << "\n" << endl;
  cout << "InOrder :" << endl;
  inOrder(nodeE);
  cout << "\n" << endl;
  cout << "PostOrder :" << endl;
  postOrder(nodeE);
  cout << "\n" << endl;

  // Menampilkan karakteristik pohon seperti ukuran, tinggi, dan rata-rata jumlah node
  charateristic();

  // Menghapus subtree yang dimulai dari node E
  deleteSub(nodeE);

  // Menampilkan traversal PreOrder setelah subtree dihapus
  cout << "\nPreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;

  // Menampilkan karakteristik pohon setelah subtree dihapus
  charateristic();
}
