/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif

extern char **environ;

int main(int argc, char* argv[]) {
  int i=1;
  while(putenv(argv[i]) != -1) {
    i++;
  }
  if(i == argc) {
    for(int j=0; environ[j] != NULL ; j++) {
      printf("%s\n", environ[j]);
    }
  }
  else {
    execvp(argv[i],&argv[i]);
    perror("execvp");
  }
  return 0;
}
/* 実行例
1 コンパイル結果
% make
cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c myputenv.c
%

2 実行(引数なし)
% ./myenv
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/zsh
TERM=xterm-256color
TMPDIR=/var/folders/3d/6p7bmy8577sbsw_gqvstgyjm0000gn/T/
TERM_PROGRAM_VERSION=470.2
TERM_SESSION_ID=28E53D50-15BE-4DDF-ACD1-61A993B7A85B
USER=katsuhara
SSH_AUTH_SOCK=/var/run/com.apple.launchd.TPyT8nxS3G/Listeners
PATH=/Users/katsuhara/.rbenv/shims:/opt/anaconda3/bin:/opt/anaconda3/condabin:/opt/homebrew/bin:/opt/homebrew/sbin:/Library/Frameworks/Python.framework/Versions/3.14/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/pkg/env/global/bin:/Library/TeX/texbin
__CFBundleIdentifier=com.apple.Terminal
PWD=/Users/katsuhara/Library/CloudStorage/OneDrive-独立行政法人国立高等専門学校機構/SysPro/kadai09-i23katuhara
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/katsuhara
LOGNAME=katsuhara
OSLogRateLimit=64
COLORTERM=truecolor
OLDPWD=/Users/katsuhara/Library/CloudStorage/OneDrive-独立行政法人国立高等専門学校機構/SysPro
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
FPATH=/opt/homebrew/share/zsh/site-functions:/usr/local/share/zsh/site-functions:/usr/share/zsh/site-functions:/usr/share/zsh/5.9/functions
INFOPATH=/opt/homebrew/share/info:
CONDA_EXE=/opt/anaconda3/bin/conda
_CE_M=
_CE_CONDA=
CONDA_PYTHON_EXE=/opt/anaconda3/bin/python
CONDA_SHLVL=1
CONDA_PREFIX=/opt/anaconda3
CONDA_DEFAULT_ENV=base
CONDA_PROMPT_MODIFIER=(base) 
GSETTINGS_SCHEMA_DIR_CONDA_BACKUP=
GSETTINGS_SCHEMA_DIR=/opt/anaconda3/share/glib-2.0/schemas
RBENV_SHELL=zsh
LANG=ja_JP.UTF-8
_=/Users/katsuhara/Library/CloudStorage/OneDrive-烫?竃?胁??惴?泃?人僻?竃?髃?筃?専郶?学惀??橃?槃?/SysPro/kadai09-i23katuhara/./myenv
% 

3 実行例(引数1)
3.1　引数が環境変数=値
% ./myenv LC_TIME=ja_JP.UTF-8
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/zsh
TERM=xterm-256color
TMPDIR=/var/folders/3d/6p7bmy8577sbsw_gqvstgyjm0000gn/T/
TERM_PROGRAM_VERSION=470.2
TERM_SESSION_ID=28E53D50-15BE-4DDF-ACD1-61A993B7A85B
USER=katsuhara
SSH_AUTH_SOCK=/var/run/com.apple.launchd.TPyT8nxS3G/Listeners
PATH=/Users/katsuhara/.rbenv/shims:/opt/anaconda3/bin:/opt/anaconda3/condabin:/opt/homebrew/bin:/opt/homebrew/sbin:/Library/Frameworks/Python.framework/Versions/3.14/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/pkg/env/global/bin:/Library/TeX/texbin
__CFBundleIdentifier=com.apple.Terminal
PWD=/Users/katsuhara/Library/CloudStorage/OneDrive-独立行政法人国立高等専門学校機構/SysPro/kadai09-i23katuhara
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/katsuhara
LOGNAME=katsuhara
OSLogRateLimit=64
COLORTERM=truecolor
OLDPWD=/Users/katsuhara/Library/CloudStorage/OneDrive-独立行政法人国立高等専門学校機構/SysPro
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
FPATH=/opt/homebrew/share/zsh/site-functions:/usr/local/share/zsh/site-functions:/usr/share/zsh/site-functions:/usr/share/zsh/5.9/functions
INFOPATH=/opt/homebrew/share/info:
CONDA_EXE=/opt/anaconda3/bin/conda
_CE_M=
_CE_CONDA=
CONDA_PYTHON_EXE=/opt/anaconda3/bin/python
CONDA_SHLVL=1
CONDA_PREFIX=/opt/anaconda3
CONDA_DEFAULT_ENV=base
CONDA_PROMPT_MODIFIER=(base) 
GSETTINGS_SCHEMA_DIR_CONDA_BACKUP=
GSETTINGS_SCHEMA_DIR=/opt/anaconda3/share/glib-2.0/schemas
RBENV_SHELL=zsh
LANG=ja_JP.UTF-8
_=/Users/katsuhara/Library/CloudStorage/OneDrive-烫?竃?胁??惴?泃?人僻?竃?髃?筃?専郶?学惀??橃?槃?/SysPro/kadai09-i23katuhara/./myenv
LC_TIME=ja_JP.UTF-8
% 


3.2　引数がコマンド
% ./myenv ls -l
total 384
-rw-r--r--  1 katsuhara  staff     132  6月 30 10:53 Makefile
-rwxr-xr-x  1 katsuhara  staff   33736  7月  1 10:40 myenv
-rw-r--r--  1 katsuhara  staff     501  7月  1 10:40 myenv.c
-rwxr-xr-x  1 katsuhara  staff     216  6月 30 10:53 myputenv.c
-rw-r--r--  1 katsuhara  staff      93  6月 30 10:53 myputenv.h
-rw-r--r--  1 katsuhara  staff    1268  6月 30 10:53 README.md
-rw-r--r--  1 katsuhara  staff  139098  6月 30 10:53 README.pdf
%

4　実行例(引数2)
4.1 引数が二つとも環境変数=値
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba
TERM_PROGRAM=Apple_Terminal
SHELL=/bin/zsh
TERM=xterm-256color
TMPDIR=/var/folders/3d/6p7bmy8577sbsw_gqvstgyjm0000gn/T/
TERM_PROGRAM_VERSION=470.2
TERM_SESSION_ID=28E53D50-15BE-4DDF-ACD1-61A993B7A85B
USER=katsuhara
SSH_AUTH_SOCK=/var/run/com.apple.launchd.TPyT8nxS3G/Listeners
PATH=/Users/katsuhara/.rbenv/shims:/opt/anaconda3/bin:/opt/anaconda3/condabin:/opt/homebrew/bin:/opt/homebrew/sbin:/Library/Frameworks/Python.framework/Versions/3.14/bin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/pkg/env/global/bin:/Library/TeX/texbin
__CFBundleIdentifier=com.apple.Terminal
PWD=/Users/katsuhara/Library/CloudStorage/OneDrive-独立行政法人国立高等専門学校機構/SysPro/kadai09-i23katuhara
XPC_FLAGS=0x0
XPC_SERVICE_NAME=0
SHLVL=1
HOME=/Users/katsuhara
LOGNAME=katsuhara
OSLogRateLimit=64
COLORTERM=truecolor
OLDPWD=/Users/katsuhara/Library/CloudStorage/OneDrive-独立行政法人国立高等専門学校機構/SysPro
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
FPATH=/opt/homebrew/share/zsh/site-functions:/usr/local/share/zsh/site-functions:/usr/share/zsh/site-functions:/usr/share/zsh/5.9/functions
INFOPATH=/opt/homebrew/share/info:
CONDA_EXE=/opt/anaconda3/bin/conda
_CE_M=
_CE_CONDA=
CONDA_PYTHON_EXE=/opt/anaconda3/bin/python
CONDA_SHLVL=1
CONDA_PREFIX=/opt/anaconda3
CONDA_DEFAULT_ENV=base
CONDA_PROMPT_MODIFIER=(base) 
GSETTINGS_SCHEMA_DIR_CONDA_BACKUP=
GSETTINGS_SCHEMA_DIR=/opt/anaconda3/share/glib-2.0/schemas
RBENV_SHELL=zsh
LANG=ja_JP.UTF-8
_=/Users/katsuhara/Library/CloudStorage/OneDrive-烫?竃?胁??惴?泃?人僻?竃?髃?筃?専郶?学惀??橃?槃?/SysPro/kadai09-i23katuhara/./myenv
LC_TIME=ja_JP.UTF-8
TZ=Cuba
% 

4.2　引数が環境変数=値 コマンド
% ./myenv LC_TIME=ja_JP.UTF-8 ls -l
total 384
-rw-r--r--  1 katsuhara  staff     132  6月 30 10:53 Makefile
-rwxr-xr-x  1 katsuhara  staff   33736  7月  1 10:40 myenv
-rw-r--r--  1 katsuhara  staff     501  7月  1 10:40 myenv.c
-rwxr-xr-x  1 katsuhara  staff     216  6月 30 10:53 myputenv.c
-rw-r--r--  1 katsuhara  staff      93  6月 30 10:53 myputenv.h
-rw-r--r--  1 katsuhara  staff    1268  6月 30 10:53 README.md
-rw-r--r--  1 katsuhara  staff  139098  6月 30 10:53 README.pdf
% 

4.3　引数がコマンド　環境変数=値
% ./myenv ls TZ=Cuba   
ls: TZ=Cuba: No such file or directory
% 

4.4　引数が二つともコマンド
% ./myenv ls pwd
ls: pwd: No such file or directory
% 

5 実行例(引数3)
5.1　引数が環境変数=値　環境変数=値　コマンド
% ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ls -l
total 384
-rw-r--r--  1 katsuhara  staff     132  6月 29 21:53 Makefile
-rwxr-xr-x  1 katsuhara  staff   33736  6月 30 21:40 myenv
-rw-r--r--  1 katsuhara  staff     501  6月 30 21:40 myenv.c
-rwxr-xr-x  1 katsuhara  staff     216  6月 29 21:53 myputenv.c
-rw-r--r--  1 katsuhara  staff      93  6月 29 21:53 myputenv.h
-rw-r--r--  1 katsuhara  staff    1268  6月 29 21:53 README.md
-rw-r--r--  1 katsuhara  staff  139098  6月 29 21:53 README.pdf
% 

なお、引数が3つ以上の場合でもコマンドの後に引数があると4.3,4.4
のようなエラーが起こるような結果が得られた。

*/
