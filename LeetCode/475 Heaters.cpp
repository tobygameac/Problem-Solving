class Solution {
 
 public:
  
   int findRadius(std::vector<int> &houses, std::vector<int> &heaters) {
     std::sort(heaters.begin(), heaters.end());
     int max_radius = 0;
     for (int position : houses) {
       int l = heaters.front();
       int r = heaters.back();
       auto lb_it = std::lower_bound(heaters.begin(), heaters.end(), position);
       if (lb_it != heaters.end()) {
         r = *lb_it;
         if (lb_it != heaters.begin()) {
           l = *(lb_it - 1);
         }
       }
       int radius = std::min(std::abs(position - l), std::abs(position - r));
       max_radius = std::max(max_radius, radius);
     }
     return max_radius;
   }

};
