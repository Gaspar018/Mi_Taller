import qrcode

# IP del ESP32
esp32_ip = "192.168.2.2"

# Cada máquina con su ID en Firebase
maquinas = {
    "Máquina 1": "7nTVCNsPvchkU3jyJWC1",
    "Máquina 2": "B5xYF8aL9qkZtH2pM1vR"
}

# Generar un solo QR por máquina
for nombre, maquinaId in maquinas.items():
    # URL que contendrá el QR
    url = f"http://{esp32_ip}/control?maquinaId={maquinaId}"

    qr = qrcode.QRCode(
        version=1,
        box_size=10,
        border=4
    )
    qr.add_data(url)
    qr.make(fit=True)
    img = qr.make_image(fill_color="black", back_color="white")

    # Guardar QR
    img.save(f"{nombre}.png")
    print(f"QR generado: {nombre}.png -> {url}")
