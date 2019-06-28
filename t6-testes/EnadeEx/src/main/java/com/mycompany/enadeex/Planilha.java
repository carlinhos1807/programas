/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.enadeex;

import java.util.ArrayList;
import java.util.List;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

/**
 *
 * @author Carlinhos
 */
public class Planilha {
    public NewClass t;
    public Planilha(NewClass t){
        this.t = t;
    }
    public boolean load(){
        Arquivo n = new Arquivo("enade.csv",t.url);
        t.records = n.leArquivo();
        if(t.records.isEmpty()){
            Arquivo a = new Arquivo("enade.csv",t.url);
            if(!a.baixaArquivo()){
                return false;
            }
        }
        t.records = n.leArquivo();
        ArrayList<Enade> teste = new ArrayList<>();
        int i = 1;
        for(i = 1; i < t.records.size();i++){
            Enade e = new Enade(t.records.get(i).get(1),t.records.get(i).get(2),t.records.get(i).get(3),
            t.records.get(i).get(4),t.records.get(i).get(5),t.records.get(i).get(8),t.records.get(i).get(9),t.records.get(i).get(10),
            t.records.get(i).get(11));
            teste.add(e);
        }
        //Enade w = new Enade(records.get(0).get(0), "ta", "ta","ta","ta","ta","ta","ta","ta");
        
        t.data  =
        FXCollections.observableArrayList(
            teste
            
            
        );
        return true;
    }
    public boolean reload(){
        Arquivo a = new Arquivo("enade.csv",t.url);
        if(!a.baixaArquivo()){
            return false;
        }
        Arquivo n = new Arquivo("enade.csv",t.url);
        
        t.records = n.leArquivo();
        ArrayList<Enade> teste = new ArrayList<>();
        int i = 1;
        for(i = 1; i < t.records.size();i++){
            Enade e = new Enade(t.records.get(i).get(1),t.records.get(i).get(2),t.records.get(i).get(3),
            t.records.get(i).get(4),t.records.get(i).get(5),t.records.get(i).get(8),t.records.get(i).get(9),t.records.get(i).get(10),
            t.records.get(i).get(11));
            teste.add(e);
        }
        //Enade w = new Enade(records.get(0).get(0), "ta", "ta","ta","ta","ta","ta","ta","ta");
        
        t.data  =
        FXCollections.observableArrayList(
            teste
            
            
        );
        return true;
    }
}
