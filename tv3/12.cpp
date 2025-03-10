// Implementação da classe Jogador

// Construtor com parâmetro nome
Jogador::Jogador(string nome) {
    nomeJogador = nome;
    golsMarcados = 0;
}

// Construtor padrão
Jogador::Jogador() {
    nomeJogador = "";
    golsMarcados = 0;
}

// Método para obter o nome do jogador
string Jogador::getNome() {
    return nomeJogador;
}

// Método para obter a quantidade de gols
int Jogador::getGols() {
    return golsMarcados;
}

// Método para definir a quantidade de gols
void Jogador::setGols(int val) {
    golsMarcados = val;
}

// Implementação da classe Equipe

// Construtor padrão
Equipe::Equipe() {
    n = 0;
    jogadores = new Jogador*[MAX_JOG];
}

// Construtor de cópia
Equipe::Equipe(const Equipe& outra) {
    n = outra.n;
    jogadores = new Jogador*[MAX_JOG];
    for (int i = 0; i < n; i++) {
        jogadores[i] = new Jogador(*outra.jogadores[i]);
    }
}

// Método para adicionar um novo jogador
void Equipe::novoJogador(string nome, int gols) {
    if (n < MAX_JOG) {
        jogadores[n] = new Jogador(nome);
        jogadores[n]->setGols(gols);
        n++;
    }
    // Se o vetor estiver cheio, não faz nada conforme especificado
}

// Método para encontrar o artilheiro
string Equipe::nomeArtilheiro() {
    if (n == 0) {
        return ""; // Se não houver jogadores, retorna string vazia
    }
    
    int indiceArtilheiro = 0;
    int maxGols = jogadores[0]->getGols();
    
    for (int i = 1; i < n; i++) {
        if (jogadores[i]->getGols() > maxGols) {
            maxGols = jogadores[i]->getGols();
            indiceArtilheiro = i;
        }
    }
    
    return jogadores[indiceArtilheiro]->getNome();
}

// Método para imprimir todos os jogadores
void Equipe::imprimeJogadores() {
    for (int i = 0; i < n; i++) {
        cout << "Jogador: " << jogadores[i]->getNome() 
             << ", Gols: " << jogadores[i]->getGols() << endl;
    }
}

// Destrutor para liberar a memória
Equipe::~Equipe() {
    for (int i = 0; i < n; i++) {
        delete jogadores[i];
    }
    delete[] jogadores;
}
