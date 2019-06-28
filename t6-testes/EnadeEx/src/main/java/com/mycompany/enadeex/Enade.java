/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.enadeex;

import javafx.beans.property.SimpleStringProperty;

/**
 *
 * @author Carlinhos
 */
public class Enade {
        public final SimpleStringProperty ano;
        public final SimpleStringProperty prova;
        public final SimpleStringProperty tipoQuestao;
        public final SimpleStringProperty idQuestao;
        public final SimpleStringProperty objeto;
        public final SimpleStringProperty acertosCurso;
        public final SimpleStringProperty acertosRegiao;
        public final SimpleStringProperty acertosBrasil;
        public final SimpleStringProperty dif;
        public final SimpleStringProperty gabarito;
        public final SimpleStringProperty url;

    public Enade(String ano, String prova, String tipoQuestao, String idQuestao, String objeto, String acertosCurso, String acertosRegiao, String acertosBrasil, String dif) {
        this.ano = new SimpleStringProperty(ano);
        this.prova = new SimpleStringProperty(prova);
        this.tipoQuestao = new SimpleStringProperty(tipoQuestao);
        this.idQuestao = new SimpleStringProperty(idQuestao);
        this.objeto = new SimpleStringProperty(objeto);
        this.acertosCurso = new SimpleStringProperty(acertosCurso);
        this.acertosRegiao = new SimpleStringProperty(acertosRegiao);
        this.acertosBrasil = new SimpleStringProperty(acertosBrasil);
        this.dif = new SimpleStringProperty(dif);
        this.gabarito = new SimpleStringProperty("bug");
        this.url = new SimpleStringProperty("bug");
    }
    public Enade(String ano, String prova, String tipoQuestao, String idQuestao, String objeto, String acertosCurso, String acertosRegiao, String acertosBrasil, String dif, String gabarito, String url) {
        this.ano = new SimpleStringProperty(ano);
        this.prova = new SimpleStringProperty(prova);
        this.tipoQuestao = new SimpleStringProperty(tipoQuestao);
        this.idQuestao = new SimpleStringProperty(idQuestao);
        this.objeto = new SimpleStringProperty(objeto);
        this.acertosCurso = new SimpleStringProperty(acertosCurso);
        this.acertosRegiao = new SimpleStringProperty(acertosRegiao);
        this.acertosBrasil = new SimpleStringProperty(acertosBrasil);
        this.dif = new SimpleStringProperty(dif);
        this.gabarito = new SimpleStringProperty(gabarito);
        this.url = new SimpleStringProperty(url);
    }
    public String getAno() {
        return ano.get();
    }
    public String getUrl() {
        return url.get();
    }
    public String getGabarito() {
        return gabarito.get();
    }
    public String getProva() {
        return prova.get();
    }
    public String getTipoQuestao() {
        return tipoQuestao.get();
    }
    public String getIdQuestao() {
        return idQuestao.get();
    }
    public String getObjeto() {
        return objeto.get();
    }
    public String getAcertosCurso() {
        return acertosCurso.get();
    }
    public String getAcertosRegiao() {
        return acertosRegiao.get();
    }
    public String getAcertosBrasil() {
        return acertosBrasil.get();
    }
    public String getDif() {
        return dif.get();
    }
    

    
     
        
    
}
