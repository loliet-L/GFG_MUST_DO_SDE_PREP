#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


// !QUESTION





// !  SOLUTION



//Floyd’s Cycle-Finding Algorithm 
//Here we will use two pointers slow and fast 
//where slow will travel one step and fast two step
//if they become same at some time there is cycle
//if fast is null then there is no cycle

//Time complexity: O(n)
//Space complexity: O(1)
    bool hasCycle(ListNode *head) {
	
		// making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;
        
		// till fast and fast-> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
			
			// At the point if fast and slow are at same address
			// this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }
        
		// if traversal reaches to NULL this means no cycle.
        return false;
    }