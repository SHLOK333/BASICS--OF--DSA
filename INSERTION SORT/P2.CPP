void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
       
       
       
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        arr[j + 1] = key;
    }
}



class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Create a dummy node with a very large value
        ListNode* dummy = new ListNode(10000);
        
        // Iterate through the original linked list
        while (head) {
            // Store the next node of the current node
            ListNode* next = head->next;
            
            // Start from the beginning of the sorted part (dummy node)
            ListNode* temp = dummy;
            
            // Find the correct position for insertion in the sorted part
            // Loop until reaching the end of the sorted part or finding a node with a value >= current node
            while (temp->next && temp->next->val < head->val) {
                temp = temp->next;
            }
            
            // Insert the current node into the sorted part
            // Adjust pointers to include the current node
            head->next = temp->next;
            temp->next = head;
            
            // Move to the next node in the original list
            head = next;
        }
        
        // Return the next node of the dummy node, which represents the head of the sorted list
        return dummy->next;
    }
};



