package app;

import javax.microedition.io.Connector;
import javax.microedition.io.StreamConnection;
import java.io.IOException;
import java.io.OutputStream;

public class BluetoothHC05Connector {
    String urlScheme = "btspp";
    String macAddress = "98D311FC129A";
    String channelNum = "1";
    String bluetoothUrl = String.format("%s://%s:%s", urlScheme, macAddress, channelNum);
    StreamConnection streamConnection;
    OutputStream outputStream;

    public BluetoothHC05Connector(){}

    public BluetoothHC05Connector(String urlScheme, String macAddress, String channelNum){
        this.urlScheme = urlScheme;
        this.macAddress = macAddress;
        this.channelNum = channelNum;
    }

    public void connectToDevice(){
        try{
            streamConnection = (StreamConnection) Connector.open(bluetoothUrl);
            outputStream = streamConnection.openOutputStream();
            System.out.println("Device Connected");
        } catch (IOException e){
            System.out.println(e.getMessage());
        }
    }

    public void writeToDevice(String data){
        try{
            outputStream.write(data.getBytes());
        } catch (IOException e){
            System.out.println(e.getMessage());
        }

    }
}
