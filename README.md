# Java Solutions to Assignment 1

UID: 22BCS14972

## Arrays Problems

### 1. Remove Duplicates from a Sorted Array
```java
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int sz = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[sz-1]) {
                nums[sz] = nums[i];
                sz++;
            }
        }
        return sz;
    }
}
```

### 2. Implementing Insertion Sort
```java
class Solution {
    public void insertionSort(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
}
```

### 3. Contains Duplicate
```java
import java.util.Arrays;

class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
    }
}
```

### 4. Two Sum
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[] { map.get(complement), i };
            }
            map.put(nums[i], i);
        }
        return new int[0];
    }
}
```

### 5. Jump Game
```java
class Solution {
    public boolean canJump(int[] nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = Math.max(maxReach, nums[i] + i);
        }
        return true;
    }
}
```

### 6. Majority Element
```java
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int count = nums.length / 2;
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            if (map.get(num) > count) {
                return num;
            }
        }
        return -1;
    }
}
```

### 7. Valid Palindrome
```java
class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder res = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (Character.isLetterOrDigit(c)) {
                res.append(Character.toLowerCase(c));
            }
        }
        String cleaned = res.toString();
        return cleaned.equals(new StringBuilder(cleaned).reverse().toString());
    }
}
```

### 8. Jump Game 2
```java
class Solution {
    public int jump(int[] nums) {
        int near = 0, far = 0, jumps = 0;
        while (far < nums.length - 1) {
            int farthest = 0;
            for (int i = near; i <= far; i++) {
                farthest = Math.max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }
        return jumps;
    }
}
```

### 9. 3Sum
```java
import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (total > 0) {
                    k--;
                } else if (total < 0) {
                    j++;
                } else {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                }
            }
        }
        return res;
    }
}
```

### 10. Set Matrix Zeroes
```java
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[] row = new boolean[m];
        boolean[] col = new boolean[n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
```

### 11. Longest Substring Without Repeating Characters
```java
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int maxLength = 0;
        Set<Character> charSet = new HashSet<>();
        
        for (int right = 0; right < s.length(); right++) {
            while (charSet.contains(s.charAt(right))) {
                charSet.remove(s.charAt(left));
                left++;
            }
            charSet.add(s.charAt(right));
            maxLength = Math.max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
}
```

### 12. Find the Duplicate Number
```java
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        for (int num : nums) {
            if (!seen.add(num)) {
                return num;
            }
        }
        return -1;
    }
}
```

## Linked List Problems

### 1. Print Linked List
```java
class Solution {
    public void printList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }
    }
}
```

### 2. Remove Duplicates from Sorted List
```java
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode current = head;
        while (current != null && current.next != null) {
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
        return head;
    }
}
```

### 3. Reverse a Linked List
```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode current = head;
        
        while (current != null) {
            ListNode nextTemp = current.next;
            current.next = prev;
            prev = current;
            current = nextTemp;
        }
        
        return prev;
    }
}
```

### 4. Delete the Middle Node of a List
```java
class Solution {
    public ListNode deleteMiddle(ListNode head) {
        if (head.next == null) return null;
        
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;
        
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            prev = slow;
            slow = slow.next;
        }
        
        prev.next = slow.next;
        return head;
    }
}
```

### 5. Merge Two Sorted Linked Lists
```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        
        current.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }
}
```

### 6. Remove Duplicates from Sorted Lists II
```java
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        
        while (head != null) {
            if (head.next != null && head.val == head.next.val) {
                while (head.next != null && head.val == head.next.val) {
                    head = head.next;
                }
                prev.next = head.next;
            } else {
                prev = prev.next;
            }
            head = head.next;
        }
        
        return dummy.next;
    }
}
```

### 7. Detect Cycle in a Linked List
```java
class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null) return false;
        
        ListNode slow = head;
        ListNode fast = head;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) return true;
        }
        
        return false;
    }
}
```

### 8. Reverse Linked List II
```java
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null) return null;
        
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        
        for (int i = 0; i < left - 1; i++) {
            prev = prev.next;
        }
        
        ListNode start = prev.next;
        ListNode then = start.next;
        
        for (int i = 0; i < right - left; i++) {
            start.next = then.next;
            then.next = prev.next;
            prev.next = then;
            then = start.next;
        }
        
        return dummy.next;
    }
}
```

### 9. Rotate Linked List
```java
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) return head;
        
        int length = 1;
        ListNode tail = head;
        while (tail.next != null) {
            tail = tail.next;
            length++;
        }
        
        k = k % length;
        if (k == 0) return head;
        
        tail.next = head;
        ListNode newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail.next;
        }
        
        ListNode newHead = newTail.next;
        newTail.next = null;
        
        return newHead;
    }
}
```

### 10. Merge k Sorted Lists
```java
import java.util.PriorityQueue;

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> minHeap = new PriorityQueue<>((a, b) -> a.val - b.val);
        
        for (ListNode node : lists) {
            if (node != null) {
                minHeap.offer(node);
            }
        }
        
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        
        while (!minHeap.isEmpty()) {
            ListNode node = minHeap.poll();
            current.next = node;
            current = current.next;
            
            if (node.next != null) {
                minHeap.offer(node.next);
            }
        }
        
        return dummy.next;
    }
}
```

### 11. Sort a Linked List
```java
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        
        // Split the list
        ListNode slow = head;
        ListNode fast = head.next;
        
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        ListNode mid = slow.next;
        slow.next = null;
        
        // Recursively sort
        ListNode left = sortList(head);
        ListNode right = sortList(mid);
        
        // Merge
        return mergeLists(left, right);
    }
    
    private ListNode mergeLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                current.next = l1;
                l1 = l1.next;
            } else {
                current.next = l2;
                l2 = l2.next;
            }
            current = current.next;
        }
        
        current.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }
}
```
