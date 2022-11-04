    int n=s.length(),x,y;
    for(int i=0,j=n-1;i<j;i++,j--){
        if(s[i]!=s[j]){
            string s1=s;
            s1.erase(s1.begin()+i);
            for(x=0,y=n-2;x<y;x++,y--){
             if(s1[x]!=s1[y])
                 break;             
            }
            if(x>=y)        
            return i;            
            string s2=s;
            s2.erase(s2.begin()+j);
            for(x=0,y=n-2;x<y;x++,y--){
             if(s2[x]!=s2[y])
                 break;                
            }         
            if(x>=y)        
            return j;
            else
            return -1;
        }
    }
    return -1;  