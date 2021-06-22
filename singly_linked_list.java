class LinkedList {
    Node head;
    //oi..
    static class Node //Static faz com que não sejam criadas instâncias de um novo Node
    //Mas sim, que todos novos Nodes pertencem a llist, que é instanciada na linha 20.
    {
        int data;
        Node next;

        //construtor.
        Node (int d) 
        {
            data = d;
            next = null;
        }
    }

    /* This function prints contents of linked list starting from head */
    public void printList()
    {
        Node n = head;
        while (n != null) {
            System.out.print(n.data + " ");
            n = n.next;
        }
    }

    public void push(int new_data)
    {
        Node new_node = new Node(new_data); //instância o novo nó
        new_node.next = head; // atribui o "próximo" a cabeça
        head = new_node; //faz com que o novo seja considerado como cabeça.
    }

    /* This function is in LinkedList class.
    Inserts a new node after the given prev_node. This method is
    defined inside LinkedList class shown above */
    public void insertAfter(Node prev_node, int new_data)
    {
        /* 1. Check if the given Node is null */
        if (prev_node == null)
        {
            System.out.println("The given previous node cannot be null");
            return;
        }
    
        /* 2. Allocate the Node &
        3. Put in the data*/
        Node new_node = new Node(new_data);
    
        /* 4. Make next of new Node as next of prev_node */
        new_node.next = prev_node.next;
    
        /* 5. make next of prev_node as new_node */
        prev_node.next = new_node;
    }
    
    public static void main(String[] args) 
    {
        LinkedList llist = new LinkedList();
        llist.head = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);

        /* Three nodes have been allocated dynamically.
          We have references to these three blocks as head, 
          second and third
 
          llist.head        second              third
             |                |                  |
             |                |                  |
         +----+------+     +----+------+     +----+------+
         | 1  | null |     | 2  | null |     |  3 | null |
         +----+------+     +----+------+     +----+------+ */
 
        llist.head.next = second; // Link first node with the second node
 
         /*  Now next of the first Node refers to the second.  So they
             both are linked.
  
          llist.head        second              third
             |                |                  |
             |                |                  |
         +----+------+     +----+------+     +----+------+
         | 1  |  o-------->| 2  | null |     |  3 | null |
         +----+------+     +----+------+     +----+------+ */

         second.next = third; // Link second node with the third node
 
        /*  Now next of the second Node refers to third.  So all three
            nodes are linked.
 
         llist.head        second              third
            |                |                  |
            |                |                  |
        +----+------+     +----+------+     +----+------+
        | 1  |  o-------->| 2  |  o-------->|  3 | null |
        +----+------+     +----+------+     +----+------+ */
        
        llist.push(4);
        llist.printList();
    }

}
