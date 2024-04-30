# minishell

## 🌟 branch naming rule

- feat-기능요약 (ex : feat-parse)
- test-테스트기능요약 (ex: test-parsetest)
- fix-주요수정된버그내용 (ex: fix-segfault)
- style-주요수정내용
- docs-문서내용

## 🌟 commit rule

### Tag : Description #issue_number
ex ) Feat : Add tokenizer#2

|Tag | Description|
|-|-|
|Feat | 새로운 기능을 추가|
|Fix |	버그 수정|
|!HOTFIX |	급하게 치명적인 버그를 고쳐야하는 경우|
|Style |	코드 포맷 변경, 세미 콜론 누락, 코드 수정이 없는 경우|
|Refactor | 프로덕션 코드 리팩토링|
|Comment |	필요한 주석 추가 및 변경|
|Test	| 테스트 코드, 리펙토링 테스트 코드 추가, Production Code(실제로 사용하는 코드) 변경 없음|
|Rename |	파일 혹은 폴더명을 수정하거나 옮기는 작업만인 경우|
|Docs | 문서 수정에 대한 커밋|
|Merge | 다른 브랜치에 있는 내용을 merge 했을 경우 |

## 🌟 role

 - 파싱 트리 제작 : 솔
 - 빌트인 함수 제작 : 영기
 - 파이프 제작 :  영기
 - heredoc : 영기
 - wildcard : 솔
 - 따옴표 제거 : 솔
 - 시그널 처리 : 솔

## 🌟 1차 deadline  

 - 파싱 트리 제작 : 2024. 4. 2  
 - 빌트인 함수 제작 : 2024. 4. 2  

## 🐞 1차 Bug fix  
시작 : 2024. 4. 18


## 1차 완성  
완성 : 2024. 4. 25  

 ## 1차 평가 -> fail!!
 - env 뒤에 인자가 와도 실행함  
 - echo - n asd -> n asd를 개행 없이 출력함  
 - redirect in 상태일 때 파일을 읽고 unlink로 날려버림

## 2차 평가
2024. 4. 30 통과!!
