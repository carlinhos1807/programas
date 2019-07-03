/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Carlinhos
 */
public class Ball {
    String turn;
    
    public Ball(String turn){
        this.turn = turn;
    }
    public String getTurn(){
        return turn;
    }
    public synchronized void setTurn(String t){
        turn = t;
        notifyAll();
    }
    public synchronized void waitTurn(String t){
        long count = 0;
        while(!turn.equals(t)){
           try{ 
                wait();
           }catch(InterruptedException e){}
            count++;
        }
        System.out.println(count);
    }
}
