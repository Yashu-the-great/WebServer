webserver:
	@g++-12 -std=c++11 Server/webserver.cpp Networking/Socket.cpp FileSystems/FileSystems.cpp -o ./Build/WebServer -w 
	@echo "Put your HTML Files in the Build directory"

erase_build_server:
	

rebuild:
	@rm -rf Build/WebServer
	@echo "Previous Build Server Removed"
	@g++-12 -std=c++11 Server/webserver.cpp Networking/Socket.cpp FileSystems/FileSystems.cpp -o ./Build/WebServer -w 
	@echo "Done"