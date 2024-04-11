class Solution {
    public String removeKdigits(String num, int k) {
        LinkedList<Character> ll=new LinkedList<>();

        for(char ch:num.toCharArray())
        {
            
            while(!ll.isEmpty() && k!=0 && ll.peekLast()>ch)
            {
                ll.removeLast();
                k--;
            }
            ll.addLast(ch);
        }
        for(int i=k;i>0;i--)
        {
            ll.removeLast();
        }

        boolean frs=true;
        StringBuilder sl=new StringBuilder();

        for(char ch:ll)
        {
            if(ch=='0' && frs)
            {
                continue;
            }
            frs=false;
            sl.append(ch);
        }
          if (sl.length() == 0) return "0";
             
        return sl.toString();
    }
}