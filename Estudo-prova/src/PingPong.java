/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Carlinhos
 */
public class PingPong {
    public static void main(String[] args) {
	Ball b = new Ball("ping");
        Player pinger = new Player(b);
        Player ponger = new Player(b);
        pinger.setName("ping");
        ponger.setName("pong");
        pinger.setMate(ponger);
        ponger.setMate(pinger);
        ponger.start();
        pinger.start();
        
       
        try{
            pinger.join();
            ponger.join();
        }catch(InterruptedException e){
            
        }
    }
}
