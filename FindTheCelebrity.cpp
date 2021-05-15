/**********************FIND THE CELEBRITY******************************/
// Forward declaration of the knows API.
//OPTIMIZED => TC => O(N)  SC=>O(1)  
bool knows(int a, int b); //This fucntion Exists in the problem
int findCelebrity(int n) {
    int celeb=0;
    for(int i=1;i<n;i++){
        if(knows(celeb,i))
            celeb=i;
    }
    for(int i=0;i<n;i++){
        if(i!=celeb && knows(celeb,i) || !knows(i,celeb))
            return -1;
    }
    return celeb;
}


//My Dumb Fucntion, Not Working(jUST iGNORE! +_+)


// int findCelebrity(int n) {
//     vector<pair<pair<int, int>,bool>> celeb;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (i == j)
//                 continue;
//             if ((knows(i, j) && knows(j, i)) || (!knows(i, j) && !knows(j, i)))
//                 continue;
//             // pair<int,int> p(i,j);
//             //if (knows(i, j)) continue;
//             celeb.push_back({ { i,j }, knows(i,j)});
//         }
//     }
//     int val1, val2, found = 0;
//     for (int i = 0; i < celeb.size(); i++) {
//         val1 = celeb[i].first.first;
//         val2 = celeb[i].first.second;
//         for (int j = 0; j < celeb.size(); j++) {
//             if (i == j) continue;
//             if (!celeb[j].second) {
//                 return celeb[j].first.first;
//             }
//         }
//     }
//     return -1;
// }
