  //  tc=o(nlogn)
  // sc=o(N*2)
    bool static cmp(pair<int,int>& a, pair<int,int>& b){
            return (a.second < b.second);
    }
    int static maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> arr;
        int res=1, lastMeeting;
        
        for(int i=0;i<n;i++){
            arr.push_back({start[i],end[i]});
        }
        sort(arr.begin(),arr.end(),cmp);

        lastMeeting=arr[0].second;
        
        for(int i=1;i<arr.size();i++){
            if(arr[i].first>lastMeeting){
                res++;
                lastMeeting=arr[i].second;
            }
        }
        return res;
    }