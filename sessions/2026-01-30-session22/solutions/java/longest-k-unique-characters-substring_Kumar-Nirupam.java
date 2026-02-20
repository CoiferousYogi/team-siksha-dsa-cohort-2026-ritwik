import java.util.HashMap;
import java.util.Map;

class Solution {
    public int longestKSubstr(String s, int k) {
        //optimized        
        int left = 0 ;
        int res = -1 ;
        
        Map<Character,Integer> map = new HashMap<>();
        
        for(int right = 0 ; right<s.length();right++){
            
            //add the charatceer with its freq
            map.put(s.charAt(right) , map.getOrDefault(s.charAt(right),0)+1);
        
            // reduce the left from the window for k elements
            while(map.size()>k){
                char c = s.charAt(left); // left character
                
                map.put(c, map.get(c)-1); // reduce its freq
                
                //remove left
                if(map.get(c)==0)
                    map.remove(c);
                
                left++;
            }
            
            // add the max left of substring
            if(map.size() == k ){
                res = Math.max(res , right-left+1);
            }
        }
        return res;
    }
}