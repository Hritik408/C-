  std::cout << "\nTop view of tree" << std::endl;

    for (int i = min_level; i <= max_level; i++) {
        std::vector<node*> temp = hm[i];

        for (int j = 0; j < temp.size(); ++j)
        {
         for(int k = 0; k < 1; k++){
            std::cout << temp[k]->data << " ";
         }
         break;
        }
    }