package com.leetcode.inOrderTraversal;

import java.util.*;

public class InOrderTraversal {
    public static void main(String[] args) {
        InOrderTraversal inOrderTraversal = new InOrderTraversal();
        TreeNode treeNode = inOrderTraversal.constructTree(new Integer[]{1, 2, null, 3, 4, 5, 6, 7, 8});
        System.out.println(inOrderTraversal.inorderTraversal(treeNode));
        inOrderTraversal.preorderTraversal(treeNode);
        System.out.println();
        inOrderTraversal.sequenceTraversal(treeNode);
    }

    public List<Integer> inorderTraversal(TreeNode root) {
        LinkedList<Integer> list = new LinkedList<>();

        Stack<Object> travelStack = new Stack<>();

        travelStack.push(root);
        while (!travelStack.empty()) {
            Object o = travelStack.pop();
            if (o instanceof TreeNode) {
                travelStack.push(((TreeNode) o).right);
                travelStack.push(((TreeNode) o).val);
                travelStack.push(((TreeNode) o).left);
            } else if (o instanceof Integer) {
                list.add((Integer) o);
            }
        }

        return list;
    }

    public void preorderTraversal(TreeNode node) {
        System.out.print(node.val + ", ");
        if (node.left != null) {
            preorderTraversal(node.left);
        }
        if (node.right != null) {
            preorderTraversal(node.right);
        }
    }

    public void sequenceTraversal(TreeNode node) {
        LinkedList<TreeNode> treeNodes = new LinkedList<>();
        treeNodes.add(node);
        while (!treeNodes.isEmpty()) {
            TreeNode remove = treeNodes.remove();
            if (remove != null) {
                System.out.print(remove.val + ", ");
                treeNodes.add(remove.left);
                treeNodes.add(remove.right);
            }
        }
    }

    public TreeNode constructTree(Integer[] array) {

        TreeNode root = null;
        if (array.length > 0) {
            LinkedList<TreeNode> mainList = new LinkedList<>();
            for (Integer integer : array) {
                mainList.add(integer == null ? null : new TreeNode(integer, null, null));
            }

            LinkedList<TreeNode> treeNodeStack = new LinkedList<>();
            root = mainList.remove();
            treeNodeStack.add(root);
            while (!mainList.isEmpty()) {
                TreeNode remove = treeNodeStack.remove();
                if (remove != null) {
                    remove.left = mainList.remove();
                    if (!mainList.isEmpty()) {
                        remove.right = mainList.remove();
                    }
                    treeNodeStack.add(remove.left);
                    treeNodeStack.add(remove.right);
                }
            }
        }
        return root;
    }
}
