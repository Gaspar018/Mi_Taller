#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Elpaias";     
const char* password = "Elpepenashe"; 

WebServer server(80);

void handleControl() {
  if (server.hasArg("accion") && server.hasArg("maquinaId")) {
    String accion = server.arg("accion");    // "on" o "off"
    String maquinaId = server.arg("maquinaId");

    Serial.print("MaquinaId: "); Serial.println(maquinaId);

    // Relé 1
    if (accion == "on") {
      Serial.println("ON1");   
      server.send(200, "text/plain", "Relé 1 encendido");
    } 
    else if (accion == "off") {
      Serial.println("OFF1");  
      server.send(200, "text/plain", "Relé 1 apagado");
    } 
    else {
      server.send(400, "text/plain", "Accion invalida");
    }

  } else {
    server.send(400, "text/plain", "Falta parametro 'accion' o 'maquinaId'");
  }
}

void setup() {
  Serial.begin(9600); 
  WiFi.begin(ssid, password);

  Serial.print("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a WiFi");
  Serial.println(WiFi.localIP());

  server.on("/control", handleControl);
  server.begin();
}

void loop() {
  server.handleClient();
}
