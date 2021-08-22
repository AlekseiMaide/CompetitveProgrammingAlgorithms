    
    /**
        Klee's algorithm O(N log N)
        Find the sum of segment lenghts excluding the overlap.

        Make note of if point is start/end and based on that decide if 'overlap' is occuring.
    **/
    long long kleesAlgorithm(vector<vector<int>>& segments) {
        long long count = 0;
        long long length = 0;
        int N = segments.size();
        vector<pair<long long, bool>> points;
        
        for (int i = 0; i < N; i++) {
            points.push_back({ segments[i][0], false });
            points.push_back({ segments[i][1], true });
        }
        
        sort(points.begin(), points.end());
        
        for (int i = 0; i < points.size(); i++) {
            if (count) { // Previous point will not exist unless count > 0.
                // It is enough to find distance from previous point and add it to total length.
                length += points[i].first - points[i - 1].first;
            }
            
            (points[i].second) ? count-- : count++;
        }
        
        return length;
    }