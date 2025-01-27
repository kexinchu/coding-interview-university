请用Pro Config 编辑一个bot，可以给文章打标签

1. bot 有交互botton，可以输入文章Url
2. 可通过llm给bot打标签
3. 将标签及对应url保存在context中
4. 可以基于标签及相关性内容，搜索到对应文章的url

参考文档：

https://docs.myshell.ai/product-manual/create/pro-config-mode-beta/tutorial

https://docs.myshell.ai/product-manual/create/pro-config-mode-beta/tutorial/hello-world-with-pro-config

https://docs.myshell.ai/product-manual/create/pro-config-mode-beta/examples/pepetalk

1.24小时内完成
2.完成后回复HR邮件kris@myshell.ai


var a [5]int
var a []int

1:48 AM
select * from users where email = "100@gmail.com" or username = "jack"

UNIQUE KEY `uniq_email` (`email`)


examples:
```json
{
    "type": "automata",
    "id": "advanced_example_demo",
    "initial": "home_page_state",
    "inputs": {},
    "outputs": {},
    "context": {
      "questions_string": "[{\"question\": \"Which of the following statements is not correct? \\n A. The execution of an Automata starts from the `initial` state. \\n B. An Automata can contain multiple AtomicStates. \\n C. Each AtomicState must define both inputs and outputs. \\n D. We can define transitions in either Automata or AtomicState.\", \"answer\": \"C\", \"explanation\": \"Both inputs and outputs in an AtomicState are optional.\"}, {\"question\": \"You are building an AutomicState, please choose the correct order of execution: \\n A. inputs -> tasks -> outputs -> render \\n B. render -> inputs -> tasks -> outputs. \\n C. tasks -> inputs -> outputs -> render.  \\n D. render -> tasks -> inputs -> outputs\", \"answer\": \"A\", \"explanation\": \"The correct order is `inputs -> tasks -> outputs -> render`. Please refer to `Expressions and Variables`\"}, {\"question\": \"Which of the following expressions is not correct (assume all the variables exist)? \\n A. context.variable \\n B. variable \\n C. variable1 + variable2 \\n D. np.array(variable)\", \"answer\": \"D\", \"explanation\": \"Our expression supports JavaScript grammar.\"}]",
      "questions": "",
      "question_idx": "",
      "chosen_answer": "",
      "correct_answer": "",
      "correct_count": "",
      "memory": "{{[]}}",
      "is_correct": "{{false}}",
      "intro_message": "",
      "tts_widget_id": ""
    },
    "transitions": {
      "go_home": "home_page_state",
      "get_quiz": "quiz_page_state",
      "continue": "continue_state"
    },
    "states": {
      "home_page_state": {
        "inputs": {
          "intro_message": {
            "type": "text",
            "user_input": true,
            "default_value": "Hi, this is your Pro Config Tutorial Bot, how can I assist you today"
          },
          "tts_widget_id": {
            "type": "text",
            "user_input": true,
            "default_value": "1743159010695057408"
          }
        },
        "outputs": {
          "context.intro_message": "{{intro_message}}",
          "context.tts_widget_id": "{{tts_widget_id}}",
          "context.questions": "{{JSON.parse(context.questions_string)}}",
          "context.question_idx": "{{0}}",
          "context.correct_count": "{{0}}"
        },
        "render": {
          "text": "Welcome to this Pro Config tutorial bot. Let's start a quiz!",
          "buttons": [
            {
              "content": "Quiz",
              "description": "get_quiz",
              "on_click": "get_quiz"
            }
          ]
        }
      },
      "quiz_page_state": {
        "outputs": {
          "context.correct_answer": "{{context.questions[context.question_idx]['answer']}}"
        },
        "render": {
          "text": "{{context.question_idx + 1}}. {{context.questions[context.question_idx]['question']}}",
          "buttons": [
            {
              "content": "A.",
              "description": "Choose A.",
              "on_click": {
                "event": "check_answer",
                "payload": {
                  "chosen_answer": "A"
                }
              }
            },
            {
              "content": "B.",
              "description": "Choose B.",
              "on_click": {
                "event": "check_answer",
                "payload": {
                  "chosen_answer": "B"
                }
              }
            },
            {
              "content": "C.",
              "description": "Choose C.",
              "on_click": {
                "event": "check_answer",
                "payload": {
                  "chosen_answer": "C"
                }
              }
            },
            {
              "content": "D.",
              "description": "Choose D.",
              "on_click": {
                "event": "check_answer",
                "payload": {
                  "chosen_answer": "D"
                }
              }
            }
          ]
        },
        "transitions": {
          "check_answer": {
            "target": "analyze_answer_state",
            "target_inputs": {
              "chosen_answer": "{{payload.chosen_answer}}"
            }
          }
        }
      },
      "analyze_answer_state": {
        "inputs": {
          "chosen_answer": {
            "type": "text",
            "user_input": false
          }
        },
        "outputs": {
          "context.chosen_answer": "{{chosen_answer}}",
          "context.is_correct": "{{chosen_answer == context.correct_answer}}"
        },
        "render": {
          "text": "Check answer state."
        },
        "transitions": {
          "ALWAYS": [
            {
              "target": "correct_answer_state",
              "condition": "{{context.is_correct}}"
            },
            {
              "target": "wrong_answer_state",
              "condition": "{{true}}"
            }
          ]
        }
      },
      "correct_answer_state": {
        "outputs": {
          "context.question_idx": "{{(context.question_idx + 1) % context.questions.length}}",
          "context.correct_count": "{{context.correct_count + 1}}"
        },
        "render": {
          "text": "Congratulations! You have chosen the correct answer {{context.correct_answer}}",
          "buttons": [
            {
              "content": "Continue",
              "description": "continue",
              "on_click": "continue"
            }
          ]
        }
      },
      "wrong_answer_state": {
        "outputs": {
          "context.question_idx": "{{(context.question_idx + 1) % context.questions.length}}"
        },
        "render": {
          "text": "Oh No! The chosen answer is {{context.chosen_answer}}, while the correct one is {{context.correct_answer}}.",
          "buttons": [
            {
              "content": "Continue",
              "description": "continue",
              "on_click": "continue"
            }
          ]
        }
      },
      "continue_state": {
        "render": {
          "text": "Click to Next Question"
        },
        "transitions": {
          "ALWAYS": [
            {
              "target": "quiz_page_state",
              "condition": "{{context.question_idx > 0}}"
            },
            {
              "target": "finish_state",
              "condition": "{{context.correct_count == context.questions.length}}"
            },
            {
              "target": "review_state",
              "condition": "{{true}}"
            }
          ]
        }
      },
      "finish_state": {
        "render": {
          "text": "Congratulations! You are now a master of Pro Config!",
          "buttons": [
            {
              "content": "Home",
              "description": "Back to Home",
              "on_click": "go_home"
            }
          ]
        }
      },
      "review_state": {
        "outputs": {
          "context.memory": "{{[]}}"
        },
        "render": {
          "text": "{{context.intro_message}}"
        },
        "transitions": {
          "CHAT": "chat_page_state"
        }
      },
      "chat_page_state": {
        "inputs": {
          "user_message": {
            "type": "IM",
            "user_input": true
          }
        },
        "tasks": [
          {
            "name": "generate_reply",
            "module_type": "AnyWidgetModule",
            "module_config": {
              "widget_id": "1744214024104448000", // GPT-3.5
              "system_prompt": "You are a teacher teaching Pro Config. Pro Config is a powerful tool to build AI native applications. Here are some questions and answers about basic concepts of Pro Config: {{context.questions_string}}",
              "user_prompt": "{{user_message}}",
              "memory": "{{context.memory}}",
              "output_name": "reply"
            }
          },
          {
            "name": "generate_voice",
            "module_type": "AnyWidgetModule",
            "module_config": {
              "widget_id": "{{context.tts_widget_id}}",
              "content": "{{reply}}",
              "output_name": "reply_voice"
            }
          }
        ],
        "outputs": {
          "context.memory": "{{[...context.memory, {'user': user_message}, {'assistant': reply}]}}"
        },
        "render": {
          "text": "{{reply}}",
          "audio": "{{reply_voice}}",
          "buttons": [
            {
              "content": "Home",
              "description": "Click to Go Back to Home.",
              "on_click": "go_home"
            }
          ]
        },
        "transitions": {
          "CHAT": "chat_page_state"
        }
      }
    }
  }
```


```json
{
  "type": "automata",
  "id": "article_tagger_bot",
  "initial": "home_page_state",
  "context":{
    "article_url": {"type": "text"},
    "tag": {"type": "text"}
  },
  // "transitions": {
  //   "goto_tagging": "tagging_state",
  //   // "goto_search": "search_state",
  //   "return_home": "home_page_state"
  // },
  "states": {
    "home_page_state": {
      "type": "state",
      "render": {
        "text": "Welcome to the Article Tagging Bot! Select an action below.",
        "buttons": [
          {
            "content": "Tag an Article",
            "description": "Input an article URL to generate tags.",
            "on_click": "goto_tagging"
          }
          // {
          //   "content": "Search Articles",
          //   "description": "Search for articles by tags.",
          //   "on_click": "goto_search"
          // }
        ]
      },
      "transitions": {
        "start_demo": "home_page_state",
        "goto_tagging": "tagging_state"
      }
    },
    "tagging_state": {
      "type": "state",
      "inputs": {
        "article_url": {
          "type": "text",
          "user_input": true,
          "name":"Article URL",
          "description": "Enter article URL here."
        },
        "1": {
          "type": "text",
          "user_input": true
        }
      },
      "tasks": [
        {
          "name": "generate tag",
          "module_type": "tag_article",
          "module_config": {
            "widget_id": "1744214024104448001",
            "system_prompt": "Analyze the following article URL and generate relevant tags:",
            "user_prompt": "Here is the article_url: {{article_url}}",
            "memory": [],
            "function_name": "auto_prompt",
            "function_description": "Generate a configuration for the bot",
            "function_parameters": [
              {
                "name": "article_url",
                "type": "string",
                "description": "The inserted article url"
              },
              {
                "name": "tags",
                "type": "string",
                "description": "the generated tags"
              }
            ],
            "output_name": "results"
          }
        }
      ],
      "outputs": {
        "context.article_url": "{{results.article_url}}",
        "context.tag":"{{results.tags}}"
      },
      // "render": {
      //   "text": "{{tag_confirmation}}",
      //   "buttons": [
      //     {
      //       "content": "Back to Home",
      //       "on_click": "return_home"
      //     }
      //   ]
      // },
      "transitions": {
        "ALWAYS": "home_page_state"
      }
    }
    // "search_state": {
    //   "inputs": {
    //     "search_tag": {
    //       "type": "text",
    //       "user_input": true,
    //       "default_value": "Enter a tag to search"
    //     }
    //   },
    //   "tasks": [
    //     {
    //       "name": "search_articles",
    //       "type": "context_query",
    //       "inputs": {
    //         "query_key": "{{search_tag}}"
    //       },
    //       "outputs": {
    //         "matching_urls": "{{matching_urls}}"
    //       }
    //     }
    //   ],
    //   "outputs": {
    //     "search_result": "Here are the articles related to '{{search_tag}}':\n{{matching_urls}}"
    //   },
    //   "render": {
    //     "text": "{{search_result}}",
    //     "buttons": [
    //       {
    //         "content": "Back to Home",
    //         "on_click": "return_home"
    //       }
    //     ]
    //   }
    // }
  }
}

```