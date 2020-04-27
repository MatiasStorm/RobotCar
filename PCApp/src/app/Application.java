package app;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.*;

public class Application extends JFrame {
    JPanel jPanel = new JPanel();
    JLabel label = new JLabel("TEST");
    BluetoothHC05Connector btConnector = new BluetoothHC05Connector();

    public Application(){
        btConnector.connectToDevice();
        createActions();

        jPanel.add(label);
        jPanel.setPreferredSize(new Dimension(400, 200));
        add(jPanel);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setSize(400, 200);
        setVisible(true);
    }SDW

    private void createActions(){
        Action WAction = new AbstractAction(){
            public void actionPerformed(ActionEvent e) {
                sendAction("w");
            }
        };
        Action AAction = new AbstractAction(){
            public void actionPerformed(ActionEvent e) {
                sendAction("a");
            }
        };
        Action SAction = new AbstractAction(){
            public void actionPerformed(ActionEvent e) {
                sendAction("s");
            }
        };
        Action DAction = new AbstractAction(){
            public void actionPerformed(ActionEvent e) {
                sendAction("d");
            }
        };
        InputMap inputMap = jPanel.getInputMap(JPanel.WHEN_IN_FOCUSED_WINDOW);
        ActionMap actionMap = jPanel.getActionMap();

        inputMap.put(KeyStroke.getKeyStroke("A"), "AAction");
        actionMap.put("AAction", AAction);

        inputMap.put(KeyStroke.getKeyStroke("W"), "WAction");
        actionMap.put("WAction", WAction);

        inputMap.put(KeyStroke.getKeyStroke("S"), "SAction");
        actionMap.put("SAction", SAction);

        inputMap.put(KeyStroke.getKeyStroke("D"), "DAction");
        actionMap.put("DAction", DAction);
    }

    private void sendAction(String data){
        label.setText(data);
        btConnector.writeToDevice(data);
    }
}