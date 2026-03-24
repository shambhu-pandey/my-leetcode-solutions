/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
       List<List<Integer>> res = new ArrayList<>();

       if(root==null) return res;

       Queue<TreeNode> q = new LinkedList<>();
       q.offer(root);

       boolean rev = false; // false = left→right, true = right→left

       while(!q.isEmpty()){
        int n = q.size();
        LinkedList<Integer> level = new LinkedList<>();

        for(int i =0;i<n; i++){
            TreeNode node = q.poll();

            if(rev)
                level.addFirst(node.val); // reverse
            else
                level.addLast(node.val);

            if(node.left!=null) q.offer(node.left); 
            if(node.right!=null) q.offer(node.right);
        }
        res.add(level);

        // flip direction for next level
        rev = !rev;
       }
         return res;
    }
}