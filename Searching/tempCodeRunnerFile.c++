
    while(start <= end){
        int mid = (start + end)/2;
        if(arr[mid] == k){
            ans = mid;
            end = mid - 1;