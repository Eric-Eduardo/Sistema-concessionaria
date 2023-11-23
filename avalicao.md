
# Identificação

* Nome: Eric Eduardo Alves Azevedo

* Matrícula: 20220051953
  
# Compilação  

Para que o programa funcione, é necessário ter em sua máquina a linguagem `C++`. Para compilar o programa, basta executar o comando `make` na linha de comando. Para executar o programa, execute `bin/programa`. Abaixo segue uma lista de comandos que podem ser usados durante a execução do programa.

* `create-concessionaria [nome] [cnpj] [estoque]` cadastra uma concessionária. Esse comando recebe como valores o nome e o CNPJ da concessinária, e o estoque. Exemplo:
```
create-concessionaria Concec_SA 11.111.111/0001-11 0
``` 

* `add-car [concessionaria] [marca] [preço] [chassi] [ano] [tipo do motor]` cadastra um automóvel. Esse comando recebe como valores a concessionária no qual o automóvel pertence, a marca, chassi e ano do carro, e o tipo do motor.  Exemplo:
```
add-car Concec_SA Toyota 100000 9BRBLWHEXG0107721 2019 gasolina
``` 

* `add-bike [concessionaria] [marca] [preço] [chassi] [ano] [modelo]` cadastra uma motocicleta. Esse comando recebe como valores a concessionária no qual a motocicleta pertence, a marca, chassi, o ano e o modelo da moto.  Exemplo:
```
add-bike Concec_SA Toyota 100000 B0095WHEXG0107721 2022 esportivo
``` 

* `add-truck [concessionaria] [marca] [preço] [chassi] [ano] [tipo de carga]` cadastra um caminhão. Esse comando recebe como valores a concessionária no qual o caminhão pertence, a marca, chassi, o ano e o tipo de carga do caminhão.  Exemplo:
```
add-truck Consec_SA Scania 700000 7BRBLQHEXG0208811 2010 perigosa
``` 

* `remove-vehicle [chassi]` remove um veículo do sistema. Esse comando recebe como valor o chassi do veículo.  Exemplo:
```
remove-vehicle 7BRBLQHEXG0208811
``` 

* `quit` encerra a execução do programa.


# Limitações

* O programa não trata erros de tipos de variáveis. Então, se o usuário digitar uma string no lugar de um inteiro, pode ocasionar problemas.
* O programa não verifica se a entrada obedece um determinado padrão. Por exemplo, ao adicionar um novo automóvel, não é verificado se o tipo do motor é elétrico ou à gasolina. Caso o usuário digite algo diferente dessas opções, não será emitido um erro e o automóvel será cadastrado normalmente com o valor digitado. O mesmo ocorre com os atributos `modelo` e `tipo de carga` nas classes `Moto` e `Caminhao`.
* É permitido cadastrar concessionárias com o mesmo cnpj. Apenas não é permitido cadastrar com o mesmo nome.

# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | **10 / 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | **10 / 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | **10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | **10 / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | **10 / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **... / 15 - Bônus: ...**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **... / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **... / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **... / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **5 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **... / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **5 / 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **... / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **60 / 150 ** pontos (sem bônus)
 
 **60 / 200 ** pontos (com bônus)
