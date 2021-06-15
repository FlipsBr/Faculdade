import java.util.ArrayList;
import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;

class Projeto 
{
    public static void main(String[] args)
    {
        //Acrescentando números
        ArrayList<Integer> listaNumeros = new ArrayList<Integer>();
        Stack<Integer> stackNumeros = new Stack<Integer>();
        Queue<Integer> filaNumeros = new LinkedList<Integer>();
            

    
        for (int i = 0 ; i < 5 ; i++ )
            listaNumeros.add(i+1);
        
        for (int i = 0 ; i < 5 ; i++ ) //Passando da Lista pra Pilha.
        {   
            stackNumeros.push(listaNumeros.get(0));
            listaNumeros.remove(0);
        }
 
    
        for (int i = 0 ; i < 5 ; i++) // Passando da Pilha pra fila.
            filaNumeros.add(stackNumeros.pop());
        
        
        
        for (int i = 0 ; i < 5 ; i++ ) //Acrescentando novos itens na Lista.
            listaNumeros.add(i+6);
        
        for (int i = 0 ; i < 5 ; i++ ) //Passando da Lista pra Pilha.
        {   
            stackNumeros.push(listaNumeros.get(0));
            listaNumeros.remove(0);
        }

        for (int i = 0 ; i < 5 ; i++) // Passando da Pilha pra fila.
            filaNumeros.add(stackNumeros.pop());
        
        System.out.println(filaNumeros);

    }   
}