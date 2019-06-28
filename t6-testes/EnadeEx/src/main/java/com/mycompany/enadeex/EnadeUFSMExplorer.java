package com.mycompany.enadeex;

import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;


import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableRow;
import javafx.scene.control.TableView;
import javafx.scene.control.TextArea;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Modality;
import javafx.stage.Stage;
import org.apache.commons.lang3.SerializationUtils;

/**
 *
 * @author Carlinhos
 */
public class EnadeUFSMExplorer extends Application {
    private final TableView<Enade> table = new TableView<>();
    List<List<String>> records;
    public ObservableList<Enade> data;
    public String url;
    @Override
    public void start(Stage primaryStage) {
        records = new ArrayList<>();
        url = "https://docs.google.com/spreadsheets/d/e/2PACX-1vTO06Jdr3J1kPYoTPRkdUaq8XuslvSD5--FPMht-ilVBT1gExJXDPTiX0P3FsrxV5VKUZJrIUtH1wvN/pub?gid=0&single=true&output=csv";
        NewClass c = new NewClass(url);
        Planilha p = new Planilha(c);
        if(!p.load()){
            Alert alert = new Alert(AlertType.WARNING);
            alert.setTitle("ERRO");
            alert.setHeaderText("Erro no carregamento do arquivo!");
            alert.setContentText("Verifique se está conectado à internet e dê reload !");
            alert.showAndWait();
        }
        records = c.records;
        data = c.data;
        url = c.url;
        TextArea textArea = new TextArea();
        Label about = new Label();
        about.setText("");
        textArea.setPrefHeight(5);  //sets height of the TextArea to 400 pixels
        Button button = new Button("Alterar URL");
        button.setDisable(true);
        textArea.setEditable(false);
        
        
            //sets width of the TextArea to 300 pixels
        final Menu menuFile = new Menu("File");
        final Menu menuHelp = new Menu("Help");
        MenuItem menuItemExit = new MenuItem("Exit");
        MenuItem menuItemReload = new MenuItem("Reload");
        MenuItem menuItemSource = new MenuItem("Source");
        MenuItem menuItemAbout = new MenuItem("About");
        MenuBar menuBar = new MenuBar();
        
        //TableView table = new TableView();
        TableColumn ano = new TableColumn("Ano");
        ano.setCellValueFactory(
                new PropertyValueFactory<>("ano"));
        TableColumn prova = new TableColumn("Prova");
        prova.setCellValueFactory(
                new PropertyValueFactory<>("prova"));
        TableColumn tipoQuestao = new TableColumn("Tipo questão");
        tipoQuestao.setCellValueFactory(
                new PropertyValueFactory<>("tipoQuestao"));
        TableColumn idQuestao = new TableColumn("Id Questão");
        idQuestao.setCellValueFactory(
                new PropertyValueFactory<>("idQuestao"));
        TableColumn objeto = new TableColumn("Objeto");
        objeto.setCellValueFactory(
                new PropertyValueFactory<>("objeto"));
        TableColumn acertosCurso = new TableColumn("Acertos Curso");
        acertosCurso.setCellValueFactory(
                new PropertyValueFactory<>("acertosCurso"));
        TableColumn acertosRegiao = new TableColumn("Acertos Região");
        acertosRegiao.setCellValueFactory(
                new PropertyValueFactory<>("acertosRegiao"));
        TableColumn acertosBrasil = new TableColumn("Acertos Brasil");
        acertosBrasil.setCellValueFactory(
                new PropertyValueFactory<>("acertosBrasil"));
        TableColumn dif = new TableColumn("Dif");
        dif.setCellValueFactory(
                new PropertyValueFactory<>("dif"));
        TableColumn gabarito = new TableColumn("gabarito");
        gabarito.setCellValueFactory(
                new PropertyValueFactory<>("gabarito"));
        TableColumn url2 = new TableColumn("url");
        url2.setCellValueFactory(
                new PropertyValueFactory<>("url"));
        
        table.setItems(data);
        table.setRowFactory(tv -> {
            TableRow<Enade> row = new TableRow<>();
            row.setOnMouseClicked(event -> {
                if (event.getClickCount() == 2 && (! row.isEmpty()) ) {
                    Enade rowData = row.getItem();
                    System.out.println("Double click on: "+rowData.getAcertosBrasil());
                    Stage dialog = new Stage();
                    VBox vbox2 = new VBox();
                    vbox2.setSpacing(10);
                    
                    TableView<Enade> table2 = new TableView<>();
                    Colunas c2 = new Colunas("ano","prova","tipoQuestao","idQuestao","objeto","acertosCurso","acertosRegiao","acertosBrasil","dif","gabarito","url2");
                    table2.getColumns().addAll(c2.getAno(), c2.getProva(),c2.getTipoQuestao(),c2.getIdQuestao(),c2.getObjeto(),c2.getAcertosCurso(),c2.getAcertosRegiao(),c2.getAcertosBrasil(),c2.getDif(),c2.getGabarito(),c2.getUrl2());
                    table2.setPrefSize(800,100);
                    
                   
                    ObservableList<Enade> data2  =
               
        FXCollections.observableArrayList(
            new Enade(records.get(row.getIndex()+1).get(1),records.get(row.getIndex()+1).get(2),records.get(row.getIndex()+1).get(3),
            records.get(row.getIndex()+1).get(4),records.get(row.getIndex()+1).get(5),records.get(row.getIndex()+1).get(8),records.get(row.getIndex()+1).get(9),records.get(row.getIndex()+1).get(10),
            records.get(row.getIndex()+1).get(11),records.get(row.getIndex()+1).get(7),records.get(row.getIndex()+1).get(17))
            
            
        );
        
                    table2.setItems(data2);
                    Button button2 = new Button("Alterar URL");
                    
                    vbox2.getChildren().addAll(table2);

                    dialog.initOwner(primaryStage);
                    dialog.initModality(Modality.APPLICATION_MODAL);
                    
                    Scene scene2 = new Scene(vbox2,800 , 600);
                    dialog.setScene(scene2);
                    dialog.showAndWait();
                    
                }
            });
            return row;
        });

        table.getColumns().addAll(ano, prova,tipoQuestao,idQuestao,objeto,acertosCurso,acertosRegiao,acertosBrasil,dif);
        
        VBox vbox = new VBox();
        vbox.setSpacing(10);
        
        menuFile.getItems().addAll(menuItemReload,menuItemSource,menuItemExit);
        menuHelp.getItems().add(menuItemAbout);
        menuBar.getMenus().addAll(menuFile, menuHelp);
        vbox.getChildren().addAll(menuBar,about,table,textArea,button);
        menuItemExit.setOnAction((ActionEvent e) -> {
            primaryStage.close();
        });
        menuItemReload.setOnAction((ActionEvent e) -> {
            NewClass d = new NewClass(url);
            Planilha p2 = new Planilha(d);
            if(!p2.reload()){
                Alert alert = new Alert(AlertType.WARNING);
                alert.setTitle("ERRO");
                alert.setHeaderText("Erro no carregamento do arquivo!");
                alert.setContentText("Verifique se a URL está correta ou se está conectado à internet e dê reload !");
                alert.showAndWait();
            }else{
                records = d.records;
                data = d.data;
                url = d.url;
                table.setItems(data);
                System.out.println(records.get(0).get(0));
            }
        
        });
        menuItemSource.setOnAction((ActionEvent e) -> {
            button.setDisable(false);
            textArea.setEditable(true);
        
        });
        button.setOnAction((ActionEvent e) -> {
            url = textArea.getText();
            button.setDisable(true);
            textArea.setEditable(false);
        
        });
         menuItemAbout.setOnAction((ActionEvent e) -> {
           about.setText("ENADE UFSM Explorer feito por Carlos Alberto Rosa dos Santos");
        
        });
        
        Scene scene = new Scene(vbox, 1024, 768);
        
        primaryStage.setTitle("Hello World!");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}
