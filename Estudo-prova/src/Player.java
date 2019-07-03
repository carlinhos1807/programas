/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Carlinhos
 */
public class Player extends Thread{
    Ball b;
    Player mate;
    public Player(Ball b){
        this.b = b;
    }
    public void setMate(Player mate){
        this.mate = mate;
    }
    @Override
    public void run(){
        for(int i = 0; i < 10;i++){
            b.waitTurn(getName());
            
            System.out.println(getName());
            b.setTurn(mate.getName());
        }
    }
}
