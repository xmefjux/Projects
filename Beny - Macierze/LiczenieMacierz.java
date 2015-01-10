package main;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.text.DecimalFormat;
import java.util.Random;

import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.TableColumn;

public class LiczenieMacierz extends JFrame{
	private static final long serialVersionUID = -6346987749494476134L;
	//zmienne klasy
	int n;
	GUI gui;
	double[][] macierzA;
	double[][] macierzBack;
	double[][] macierzL;
    double[][] macierzU;
    Random randomGen;
    DecimalFormat df;
    Dimension screenSize;
    JPanel contentPane, tab1Pane, tab2Pane, tab3Pane;
    JScrollPane scroll1, scroll2, scroll3;
    JLabel label1, label2, label3;
    JTable tab1, tab2, tab3;
    TableColumn column;
	//------------------------------------------------
	LiczenieMacierz(int n, GUI gui){
		
		//czas start
		long startTime = System.nanoTime();
		//------------------------------------------------
		this.n = n;
		this.gui = gui;
		macierzA = new double[n][n];
		macierzBack = new double[n][n];
		macierzL = new double[n][n]; //dolna macierz trójkątna
	    macierzU = new double[n][n];
	    randomGen = new Random();
	    df = new DecimalFormat("#.##");
	    screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		//------------------------------------------------
		//macierz A z randomami
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<n; j++){
	    		macierzA[i][j] = randomGen.nextInt(5)+1;
	    		macierzBack[i][j] = macierzA[i][j];
	    	}
	    }
	    //------------------------------------------------
	    //Macierz L
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<n; j++){
	    		macierzL[i][j] = 0;
	    		macierzL[i][i] = 1;
	    	}
	    }
	    //Macierz U
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<n; j++){
	    		macierzU[i][j] = 0;
	    	}
	    }
	    //------------------------------------------------
	    //------------------------------------------------
	    //algorytm liczący rozkład LU
	    for(int i=0; i<n-1; i++){
	    	for(int j=i+1; j<n; j++){
	    		if(macierzA[i][i] != 0){
	    			macierzL[j][i] = (macierzA[j][i]) / (macierzA[i][i]);
	    		} else {
	    			macierzL[j][i] = 0;
	    		}
	    	}
	    	for(int j=i+1; j<n; j++){
	    		for(int k=i+1; k<n; k++){
	    			macierzA[j][k] = (macierzA[j][k]) - ((macierzL[j][i]) * (macierzA[i][k]));
	    		}
	    	}
	    }
	    //------------------------------------------------
	    //------------------------------------------------
	    contentPane = new JPanel(new GridLayout(1, 3, 20, 0));
	    
	    tab1 = new JTable(n, n);
	    tab2 = new JTable(n, n);
	    tab3 = new JTable(n, n);
	    
	    column = null;
	    for(int i=0; i<n; i++){
	    	column = tab1.getColumnModel().getColumn(i);
	    	column.setPreferredWidth(45);
	    	column = tab2.getColumnModel().getColumn(i);
	    	column.setPreferredWidth(45);
	    	column = tab3.getColumnModel().getColumn(i);
	    	column.setPreferredWidth(45);
	    }
	    
	    tab1Pane = new JPanel();
	    tab1Pane.setLayout(new BoxLayout(tab1Pane, BoxLayout.PAGE_AXIS));
	    tab2Pane = new JPanel();
	    tab2Pane.setLayout(new BoxLayout(tab2Pane, BoxLayout.PAGE_AXIS));
	    tab3Pane = new JPanel();
	    tab3Pane.setLayout(new BoxLayout(tab3Pane, BoxLayout.PAGE_AXIS));
	    
	    scroll1 = new JScrollPane(tab1Pane);
	    scroll2 = new JScrollPane(tab2Pane);
	    scroll3 = new JScrollPane(tab3Pane);
	    
	    label1 = new JLabel("Macierz A");
	    label2 = new JLabel("Macierz L");
	    label3 = new JLabel("Macierz U");
	    
	    tab1Pane.add(label1);
	    tab1Pane.add(tab1);
	    tab2Pane.add(label2);
	    tab2Pane.add(tab2);
	    tab3Pane.add(label3);
	    tab3Pane.add(tab3);
	    
	    tab1.setEnabled(false);
	    tab2.setEnabled(false);
	    tab3.setEnabled(false);
	    //------------------------------------------------
	    //zapełnianie macierzy
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<n; j++){
	    		tab1.getModel().setValueAt(df.format(macierzBack[i][j]), i, j);
	    		tab2.getModel().setValueAt(df.format(macierzL[i][j]), i, j);
	    	}
	    }
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<n; j++){
	    		macierzU[i][j] = macierzA[i][j];
	    	}
	    }
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<i; j++){
	    		macierzU[i][j] = 0;
	    	}
	    }
	    for(int i=0; i<n; i++){
	    	for(int j=0; j<n; j++){
	    		tab3.getModel().setValueAt(df.format(macierzU[i][j]), i, j);
	    	}
	    }
	 	//------------------------------------------------
	    add(contentPane);
	    contentPane.add(scroll1);
	    contentPane.add(scroll2);
	    contentPane.add(scroll3);
	    
	    this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	    this.pack();
	    this.setTitle("liczenie");
	    this.setLocation(screenSize.width / 2 - (screenSize.width / 4), screenSize.height / 2 - 250 );
	    this.setVisible(true);
	    
	    long stopTime = System.nanoTime();
	    gui.czas(stopTime - startTime);
	}
}
