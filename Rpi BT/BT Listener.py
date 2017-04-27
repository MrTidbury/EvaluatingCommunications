import bluetooth

server_sock=bluetooth.BluetoothSocket( bluetooth.RFCOMM )

server_sock.bind(("",bluetooth.PORT_ANY))
server_sock.listen(1)

bluetooth.advertise_service(server_sock, "BTPIService",
                     service_classes=[bluetooth.SERIAL_PORT_CLASS],
                     profiles=[bluetooth.SERIAL_PORT_PROFILE])

client_sock, address = server_sock.accept()

data = client_sock.recv(1024)

easygui.msgbox('Movement Sensor Triggered','WARNING')
client_sock.close()
server_sock.close()





