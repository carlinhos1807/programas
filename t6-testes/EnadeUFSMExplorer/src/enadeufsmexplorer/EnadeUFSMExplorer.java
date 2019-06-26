/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package enadeufsmexplorer;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableRow;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 *
 * @author Carlinhos
 */
public class EnadeUFSMExplorer extends Application {
    private final TableView<Enade> table = new TableView<>();
    private final ObservableList<Enade> data =
        FXCollections.observableArrayList(
            new Enade("ta2", "ta", "ta","ta","ta","ta","ta","ta","ta"),
            new Enade("tadsa", "ta", "ta","ta","ta","ta","ta","ta","ta"),
            new Enade("tadsa", "ta", "ta","ta","ta","ta","ta","ta","ta"),
            new Enade("tadsad", "ta", "ta","ta","ta","ta","ta","ta","ta"),
            new Enade("tadasd", "ta3", "ta","ta","ta","ta","ta","ta","ta")
            
        );
    
    @Override
    public void start(Stage primaryStage) {
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
        table.setItems(data);
        table.setRowFactory(tv -> {
            TableRow<Enade> row = new TableRow<>();
            row.setOnMouseClicked(event -> {
                if (event.getClickCount() == 2 && (! row.isEmpty()) ) {
                    Enade rowData = row.getItem();
                    System.out.println("Double click on: "+row.getIndex());
                }
            });
            return row ;
        });

        table.getColumns().addAll(ano, prova,tipoQuestao,idQuestao,objeto,acertosCurso,acertosRegiao,acertosBrasil,dif);
        
        VBox vbox = new VBox();
        
        menuFile.getItems().addAll(menuItemReload,menuItemSource,menuItemExit);
        menuHelp.getItems().add(menuItemAbout);
        menuBar.getMenus().addAll(menuFile, menuHelp);
        vbox.getChildren().addAll(menuBar,table);
        
        
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
