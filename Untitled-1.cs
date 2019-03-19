using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Windows;
using System.Collections.Generic;
using GraphX.PCL.Common.Enums;
using GraphX.PCL.Logic.Algorithms.LayoutAlgorithms;
using GraphX.Controls;
using SimpleGraph.Models;

namespace SimpleGraph
{
    public partial class MainWindow : Window, IDisposable
    {
        public string input_path;
        public GraphNol G_mendekati = new GraphNol(AppDomain.CurrentDomain.BaseDirectory + "Test.txt");
        public GraphSatu G_menjauhi = new GraphSatu(AppDomain.CurrentDomain.BaseDirectory + "Test.txt");
        public List<int> V_anim = new List<int>();

        public MainWindow()
        {
            InitializeComponent();

            //input_path default
            input_path = AppDomain.CurrentDomain.BaseDirectory + "Test.txt";

            //pengaturan Zoombox
            ZoomControl.SetViewFinderVisibility(zoomctrl, Visibility.Visible);
            zoomctrl.ZoomToFill();

            //setup GraphArea settings
            GraphAreaDisplay_Setup();
            
            //button click events
            gg_but_randomgraph.Click += gg_but_randomgraph_Click;
            gg_but_relayout.Click += gg_but_relayout_Click;
            ans_but.Click += ans_but_Click;
            ans_file_but.Click += ans_file_but_Click;
            create_but.Click += create_but_Click;

            //main window load event
            Loaded += MainWindow_Loaded;

        }

        void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
            gg_but_randomgraph_Click(null, null);
        }

        void create_but_Click(object sender, RoutedEventArgs e)
        {
            if (path_textbox.Text != String.Empty)
                input_path = AppDomain.CurrentDomain.BaseDirectory + path_textbox.Text;
            Dispose();
            update_all_graph();
            GraphAreaDisplay_Setup();
            gg_but_randomgraph_Click(null, null);
        }

        void update_all_graph()
        {
            G_mendekati = new GraphNol(input_path);
            G_menjauhi = new GraphSatu(input_path);
        }

        void gg_but_relayout_Click(object sender, RoutedEventArgs e)
        {
            Area.RelayoutGraph();
            zoomctrl.ZoomToFill();
        }

        void gg_but_randomgraph_Click(object sender, RoutedEventArgs e)
        {
            GraphAreaDisplay_Setup();
            Area.GenerateGraph(true, true);

            /* 
             * After graph generation is finished you can apply some additional settings for newly created visual vertex and edge controls
             * (VertexControl and EdgeControl classes).
             * 
             */

            //This method sets the dash style for edges. It is applied to all edges in Area.EdgesList. You can also set dash property for
            //each edge individually using EdgeControl.DashStyle property.
            //For ex.: Area.EdgesList[0].DashStyle = GraphX.EdgeDashStyle.Dash;
            Area.SetEdgesDashStyle(EdgeDashStyle.Solid);

            //This method sets edges arrows visibility. It is also applied to all edges in Area.EdgesList. You can also set property for
            //each edge individually using property, for ex: Area.EdgesList[0].ShowArrows = true;
            Area.ShowAllEdgesArrows(false);

            //This method sets edges labels visibility. It is also applied to all edges in Area.EdgesList. You can also set property for
            //each edge individually using property, for ex: Area.EdgesList[0].ShowLabel = true;
            Area.ShowAllEdgesLabels(false);

            zoomctrl.ZoomToFill(); 
        }
        //prosedur ans_but_Click dipanggil ketika button ans_but diklik, menampilkan jawaban dari pertanyaan yang dituliskan di textbox ans_textbox
        void ans_but_Click(object sender, RoutedEventArgs e)
        {
            ans_textbox.Text = GetTextAnswer();
        }
        void ans_file_but_Click(object sender, RoutedEventArgs e)
        {
            string path = AppDomain.CurrentDomain.BaseDirectory + "Output.txt";
            using (StreamWriter sw = File.CreateText(path))
            {
                sw.Write(GetFileAnswer(path_q_textbox.Text));
            }
            Process.Start(AppDomain.CurrentDomain.BaseDirectory + "Output.txt");
        }
        //fungsi GetTextAnswer mengembalikan jawaban dari pertanyaan yang dituliskan ke dalam textbox ans_textbox
        string GetTextAnswer()
        {
            V_anim = new List<int>();
            string s = ans_textbox.Text;
            string[] questions = Array.ConvertAll(s.Split('\n'), p => p.Trim());
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < questions.Length; i++)
            {
                sb.Append(questions[i]);
                string[] input = questions[i].Split(' ');
                if (input.Length == 3)
                {
                    int X = Convert.ToInt32(input[1]);
                    int Y = Convert.ToInt32(input[2]);
                    List<int> L = new List<int>();

                    if (input[0] == "0")
                    {
                        AnswerType A = GetAnswer(G_mendekati, X, Y, L, true);
                        if (A.GetFound())
                            sb.AppendFormat(" YA\n");
                        else
                            sb.AppendFormat(" TIDAK\n");
                        V_anim = A.GetVAns();
                        Animate_Graph(0, V_anim);
                    }
                    else if (input[0] == "1")
                    {
                        AnswerType A = GetAnswer(G_menjauhi, X, Y, L, false);
                        if (A.GetFound())
                            sb.AppendFormat(" YA\n");
                        else
                            sb.AppendFormat(" TIDAK\n");
                        V_anim = A.GetVAns();
                        Animate_Graph(1, V_anim);
                    }
                    else
                    {
                        sb.Append(" Wrong format");
                        sb.AppendLine();
                    }
                }
            }
            return sb.ToString();
        }
        //menemukan jawaban dari pertanyaan dari file eksternal dengan path yang tertulis
        string GetFileAnswer(string path)
        {
            V_anim = new List<int>();
            System.IO.StreamReader file = new System.IO.StreamReader(path);
            int N = Convert.ToInt32(file.ReadLine());
            StringBuilder sb = new StringBuilder();
            for (int i=0; i<N; i++)
            {
                string s = file.ReadLine();
                string[] input = new string[3];
                input = s.Split(' ');

                sb.Append(s.TrimEnd());

                int X = Convert.ToInt32(input[1]);
                int Y = Convert.ToInt32(input[2]);
                List<int> L = new List<int>();
                if (input[0] == "0")
                {
                    AnswerType A = GetAnswer(G_mendekati, X, Y, L, true);
                    if (A.GetFound())
                        sb.AppendFormat(" YA");
                    else
                        sb.AppendFormat(" TIDAK");
                    V_anim = A.GetVAns();
                    Animate_Graph(0, V_anim);
                }
                else if (input[0] == "1")
                {
                    AnswerType A = GetAnswer(G_menjauhi, X, Y, L, false);
                    if (A.GetFound())
                        sb.AppendFormat(" YA");
                    else
                        sb.AppendFormat(" TIDAK");
                    V_anim = A.GetVAns();
                    Animate_Graph(1, V_anim);
                }
                else
                    sb.Append("Wrong input format");
                sb.AppendLine();
            }
            return sb.ToString();
        }
        //Menggambarkan graph sesuai jalur yang terbentuk
        void Animate_Graph(int X, List<int> L)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < V_anim.Count; i++)
            {
                sb.AppendFormat("{0}", V_anim[i]);
                if (i != V_anim.Count - 1)
                    sb.AppendFormat("->");
            }
            ans_lbl.Content = sb.ToString();
            GraphAreaAnimation_Setup(X);
        }

        private GraphExample GraphDisplay_Setup()
        {
            var dataGraph = new GraphExample();
            Graph G = new GraphSatu(@input_path);
           
            for (int i=1; i<=G.GetNVertex(); i++)
            {
                string s = Convert.ToString(i);
                var dataVertex = new DataVertex(s);
                //Add vertex to data graph
                dataGraph.AddVertex(dataVertex);
            }
            var vlist = dataGraph.Vertices.ToList();
            for (int i=0; i<G.GetNVertex()-1; i++)
            {
                int from = G.GetEdges(i).GetFrom();
                int to = G.GetEdges(i).GetTo();
                var dataEdge = new DataEdge(vlist[from - 1], vlist[to - 1]);
                dataGraph.AddEdge(dataEdge);
            }
            return dataGraph;
        }
        private GraphExample GraphAnimation_Setup(int X)
        { 
            var dataGraph = new GraphExample();
            Graph G;
            if (X == 0)
                G = new GraphNol(@input_path);
            else
                G = new GraphSatu(@input_path);

            for (int i = 1; i <= G.GetNVertex(); i++)
            {
                string s = Convert.ToString(i);
                var dataVertex = new DataVertex(s);
                //Add vertex to data graph
                dataGraph.AddVertex(dataVertex);
            }
            var vlist = dataGraph.Vertices.ToList();
            for (int i = 0; i < V_anim.Count-1; i++)
            {
                var dataEdge = new DataEdge(vlist[V_anim[i]-1], vlist[V_anim[i+1]-1]);
                dataGraph.AddEdge(dataEdge);
            }
            return dataGraph;
        }

        private void GraphAreaDisplay_Setup()
        {
            //Lets create logic core and filled data graph with edges and vertices
            var logicCore = new GXLogicCoreExample() { Graph = GraphDisplay_Setup() };
            //This property sets layout algorithm that will be used to calculate vertices positions
            //Different algorithms uses different values and some of them uses edge Weight property.
            logicCore.DefaultLayoutAlgorithm = LayoutAlgorithmTypeEnum.KK;
            //Now we can set parameters for selected algorithm using AlgorithmFactory property. This property provides methods for
            //creating all available algorithms and algo parameters.
            logicCore.DefaultLayoutAlgorithmParams = logicCore.AlgorithmFactory.CreateLayoutParameters(LayoutAlgorithmTypeEnum.KK);
            //Unfortunately to change algo parameters you need to specify params type which is different for every algorithm.
            ((KKLayoutParameters)logicCore.DefaultLayoutAlgorithmParams).MaxIterations = 100;

            //This property sets vertex overlap removal algorithm.
            //Such algorithms help to arrange vertices in the layout so no one overlaps each other.
            logicCore.DefaultOverlapRemovalAlgorithm = OverlapRemovalAlgorithmTypeEnum.FSA;
            //Default parameters are created automaticaly when new default algorithm is set and previous params were NULL
            logicCore.DefaultOverlapRemovalAlgorithmParams.HorizontalGap = 50;
            logicCore.DefaultOverlapRemovalAlgorithmParams.VerticalGap = 50;

            //This property sets edge routing algorithm that is used to build route paths according to algorithm logic.
            //For ex., SimpleER algorithm will try to set edge paths around vertices so no edge will intersect any vertex.
            //Bundling algorithm will try to tie different edges that follows same direction to a single channel making complex graphs more appealing.
            logicCore.DefaultEdgeRoutingAlgorithm = EdgeRoutingAlgorithmTypeEnum.SimpleER;

            //This property sets async algorithms computation so methods like: Area.RelayoutGraph() and Area.GenerateGraph()
            //will run async with the UI thread. Completion of the specified methods can be catched by corresponding events:
            //Area.RelayoutFinished and Area.GenerateGraphFinished.
            logicCore.AsyncAlgorithmCompute = false;

            //Finally assign logic core to GraphArea object
            Area.LogicCore = logicCore;
        }
        private void GraphAreaAnimation_Setup(int X)
        {
            Area.SetEdgesDashStyle(EdgeDashStyle.Solid);
            Area.ShowAllEdgesArrows(true);

            var logicCore = new GXLogicCoreExample() { Graph = GraphAnimation_Setup(X) };
            logicCore.DefaultLayoutAlgorithm = LayoutAlgorithmTypeEnum.KK;
            logicCore.DefaultLayoutAlgorithmParams = logicCore.AlgorithmFactory.CreateLayoutParameters(LayoutAlgorithmTypeEnum.KK);
            ((KKLayoutParameters)logicCore.DefaultLayoutAlgorithmParams).MaxIterations = 100;
            logicCore.DefaultOverlapRemovalAlgorithm = OverlapRemovalAlgorithmTypeEnum.FSA;
            logicCore.DefaultOverlapRemovalAlgorithmParams.HorizontalGap = 50;
            logicCore.DefaultOverlapRemovalAlgorithmParams.VerticalGap = 50;
            logicCore.DefaultEdgeRoutingAlgorithm = EdgeRoutingAlgorithmTypeEnum.SimpleER;
            logicCore.AsyncAlgorithmCompute = false;

            Area.LogicCore = logicCore;

            Area.GenerateGraph(true, true);
            Area.ShowAllEdgesLabels(false);

            zoomctrl.ZoomToFill();

        }
        //prosedur void Dispose berguna menghapus graph yang terbentuk pada window sehingga bisa terbentuk graph dinamis
        public void Dispose()
        {
            Area.Dispose();
        }

        public struct AnswerType
        {
            bool found;
            List<int> V_ans;
            public AnswerType(bool found, List<int> V_ans)
            {
                this.found = found;
                this.V_ans = V_ans;
            }
            public bool GetFound()
            {
                return found;
            }
            public List<int> GetVAns()
            {
                return V_ans;
            }
        }

        public AnswerType GetAnswer(Graph G, int X, int Y, List<int> V_ans, bool Nol)
        {
            V_ans.Add(Y);
            if (Y == X)
            {
                AnswerType Ans = new AnswerType(true, V_ans);
                return Ans;
            }
            else
            {
                Vertex V = G.GetVertices().Find(v => v.GetVertexID() == Y);
                int N = V.GetNeighbours().Count;
                if (N == 0)
                {
                    return new AnswerType(false, V_ans);
                }
                else
                {
                    int i = 0;
                    bool found = false;
                    while (i < N && !found)
                    {
                        found = GetAnswer(G, X, V.GetNeighbours()[i], V_ans, Nol).GetFound();
                        if ((!found) && (!Nol))
                        {
                            V_ans.Add(Y);
                        }
                        i++;
                    }
                    return new AnswerType(found, V_ans);
                }
            }
        }

        public class Vertex
        {
            private int id;
            private List<int> neighbour;

            public Vertex(int id)
            {
                this.id = id;
                neighbour = new List<int>();
            }
            public int GetVertexID()
            {
                return id;
            }
            public void AddNeighbour(int new_neighbour)
            {
                this.neighbour.Add(new_neighbour);
            }
            public List<int> GetNeighbours()
            {
                return this.neighbour;
            }
        }
        public class Edge
        {
            private int from;
            private int to;
            public Edge(int a, int b)
            {
                from = a;
                to = b;
            }
            public int GetFrom()
            {
                return from;
            }
            public int GetTo()
            {
                return to;
            }
        }
        public class Graph
        {
            protected int n_vertex;
            protected List<Vertex> vertices;
            protected List<Edge> edges;
            public Graph()
            {
                vertices = new List<Vertex>();
                edges = new List<Edge>();
            }
            public int GetNVertex()
            {
                return n_vertex;
            }
            public Vertex GetVertex(int i)
            {
                return vertices[i];
            }
            public List<Vertex> GetVertices()
            {
                return vertices;
            }
            public Edge GetEdges(int i)
            {
                return edges[i];
            }
        }

        /* GraphSatu membentuk graph khusus untuk pertanyaan berupa 0 X Y dimana graph yang dibentuk menjauh dari istana raja */
        public class GraphSatu : Graph
        {
            public GraphSatu(string path)
            {
                //Read from external file
                System.IO.StreamReader file = new System.IO.StreamReader(path);
                n_vertex = Convert.ToInt32(file.ReadLine());
                for (int i = 1; i <= n_vertex; i++)
                {
                    Vertex V = new Vertex(i);
                    vertices.Add(V);
                }
                if (n_vertex > 0)
                {
                    string line = file.ReadLine();
                    while (line != null)
                    {
                        string[] tokens = new string[2];
                        tokens = line.Split(' ');
                        int A = Int32.Parse(tokens[0]);
                        int B = Int32.Parse(tokens[1]);

                        int idx = vertices.FindIndex(v => v.GetVertexID() == A);
                        vertices[idx].AddNeighbour(B);
                        Edge e = new Edge(A, B);
                        edges.Add(e);
                        line = file.ReadLine();
                    }
                }
            }
        }

        /* GraphNol membentuk graph khusus untuk pertanyaan berupa 0 X Y dimana graph yang dibentuk mengarah menuju istana raja */
        public class GraphNol : Graph
        {
            public GraphNol(string path)
            {
                //Read from external file
                System.IO.StreamReader file = new System.IO.StreamReader(path);
                n_vertex = Convert.ToInt32(file.ReadLine());
                for (int i = 1; i <= n_vertex; i++)
                {
                    Vertex V = new Vertex(i);
                    vertices.Add(V);
                }
                if (n_vertex > 0)
                {
                    string line = file.ReadLine();
                    while (line != null)
                    {
                        string[] tokens = new string[2];
                        tokens = line.Split(' ');
                        int A = Int32.Parse(tokens[0]);
                        int B = Int32.Parse(tokens[1]);

                        int idx = vertices.FindIndex(v => v.GetVertexID() == B);
                        vertices[idx].AddNeighbour(A);

                        Edge e = new Edge(B, A);
                        edges.Add(e);
                        line = file.ReadLine();
                    }
                }
            }
        }
    }

}
