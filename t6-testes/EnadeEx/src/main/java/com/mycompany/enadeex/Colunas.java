/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.enadeex;

import javafx.scene.control.TableColumn;
import javafx.scene.control.cell.PropertyValueFactory;

/**
 *
 * @author Carlinhos
 */
public class Colunas {
    public TableColumn ano;
        
    public TableColumn prova;

    public TableColumn tipoQuestao;

    public TableColumn idQuestao;

    public TableColumn objeto;

    public TableColumn acertosCurso;

    public TableColumn acertosRegiao;

    public TableColumn acertosBrasil;

    public TableColumn dif;

    public TableColumn gabarito;

    public TableColumn url2;

    public Colunas(String prim, String seg, String terc, String qua, String qui, String sex, String set, String oit, String nona, String dec, String onze) {
            this.ano = new TableColumn("Ano");
        
    this.prova = new TableColumn("Prova");

    this.tipoQuestao = new TableColumn("Tipo questão");

    this.idQuestao = new TableColumn("Id Questão");

    this.objeto = new TableColumn("Objeto");

   this.acertosCurso = new TableColumn("Acertos Curso");

    this.acertosRegiao = new TableColumn("Acertos Região");

    this.acertosBrasil = new TableColumn("Acertos Brasil");

    this.dif = new TableColumn("Dif");

    this.gabarito = new TableColumn("gabarito");

    this.url2 = new TableColumn("url");
          ano.setCellValueFactory(
                new PropertyValueFactory<>(prim));
            prova.setCellValueFactory(
                new PropertyValueFactory<>(seg));
            tipoQuestao.setCellValueFactory(
                new PropertyValueFactory<>(terc));
            idQuestao.setCellValueFactory(
                new PropertyValueFactory<>(qua));
            objeto.setCellValueFactory(
                new PropertyValueFactory<>(qui));
            acertosCurso.setCellValueFactory(
                new PropertyValueFactory<>(sex));
            acertosRegiao.setCellValueFactory(
                new PropertyValueFactory<>(set));
            acertosBrasil.setCellValueFactory(
                new PropertyValueFactory<>(oit));
            dif.setCellValueFactory(
                new PropertyValueFactory<>(nona));
            gabarito.setCellValueFactory(
                new PropertyValueFactory<>(dec));
            url2.setCellValueFactory(
                new PropertyValueFactory<>(onze));
        
    }

    public TableColumn getAno() {
        return ano;
    }

    public TableColumn getProva() {
        return prova;
    }

    public TableColumn getTipoQuestao() {
        return tipoQuestao;
    }

    public TableColumn getIdQuestao() {
        return idQuestao;
    }

    public TableColumn getObjeto() {
        return objeto;
    }

    public TableColumn getAcertosCurso() {
        return acertosCurso;
    }

    public TableColumn getAcertosRegiao() {
        return acertosRegiao;
    }

    public TableColumn getAcertosBrasil() {
        return acertosBrasil;
    }

    public TableColumn getDif() {
        return dif;
    }

    public TableColumn getGabarito() {
        return gabarito;
    }

    public TableColumn getUrl2() {
        return url2;
    }
        
        
}
