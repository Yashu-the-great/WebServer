webserver:
	@g++ -std=c++11 Server/webserver.cpp Networking/Socket.cpp FileSystems/FileSystems.cpp -o ./Build/WebServer -w 
	@echo "Put your HTML Files in the Build directory"