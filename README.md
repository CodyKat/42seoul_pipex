이 프로그램은 Intel Mac을 기준으로 작성되었습니다. (M1 Mac도 가능)

shlle에서의 파이프를 구현하고 명령을 실행하여 결과를 파일에 저장하는 프로그램입니다.

# 실행법 :
   - make를 이용해 컴파일 합니다.
   - ./pipex infile [명령어] [명령어] ... [명령어] outfile로 실행합니다
     - < infile [명령어] | [명령어] | ... | [명령어] > outfile 처럼 실행됩니다.