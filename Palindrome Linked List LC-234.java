/* Simple TLE Approach */
class Solution {
    public String reverse(String str){
        String nstr="";
        char ch;
        for (int i=0; i<str.length(); i++){
        ch= str.charAt(i); 
        nstr= ch+nstr; 
      }
        return nstr;
    }
    public boolean isPalindrome(ListNode head) {
        ListNode slow=head, fast=head;
        String s1="", s2="";
        while(fast!=null && fast.next!=null){
            s1+=Integer.toString(slow.val);
            slow=slow.next;
            fast=fast.next;
            fast=fast.next;
        }
        while(slow!=null){
            s2+=Integer.toString(slow.val);
            slow=slow.next;
        }
        s2=reverse(s2);
        if(s2.length()!=s1.length()){
            s2=s2.substring(0, s2.length() - 1);
        }
        return s1.equals(s2);
    }
}

// Most optimal approach
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode curr=head, next=head, prev=null;
        while(next!=null && next.next!=null){
            curr=curr.next;
            next=next.next.next;
        }
        while(curr!=null){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
            
        }
        curr=prev;
        while(curr!=null){
            if(curr.val!=head.val){
                return false;
            }
            curr=curr.next;
            head=head.next;
        }
        return true;
    }
}