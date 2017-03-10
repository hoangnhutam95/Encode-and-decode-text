#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
  char cmd[200];
  FILE *conf;

  sprintf( cmd, "mkdir -p /andromeda/server");
  system(cmd);

  sprintf( cmd, "mkdir -p /andromeda/client");
  system(cmd);

  sprintf( cmd, "chmod 777 /andromeda/server");
  system(cmd);

  sprintf( cmd, "chmod 777 /andromeda/client");
  system(cmd);

  sprintf( cmd, "mkdir -p /andromeda");
  system(cmd);

  conf = fopen("/andromeda/server/config.conf", "w");
  if( NULL == conf){
    printf("Can't create config-server file!\n");
    return 1;
  }
  fprintf(conf, "10001\n");
  fclose(conf);

  conf = fopen("/andromeda/client/config.conf", "w");
  if( NULL == conf){
    printf("Can't create config-client file!\n");
    return 1;
  }
  fprintf(conf, "10001\nlocalhost");
  fclose(conf);

  sprintf( cmd, "chmod 777 /andromeda/server/config.conf");
  system(cmd);
  
  sprintf( cmd, "chmod 777 /andromeda/client/config.conf");
  system(cmd);

  return 0;
}
